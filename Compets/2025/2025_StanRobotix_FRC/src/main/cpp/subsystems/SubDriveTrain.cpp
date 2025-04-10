// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <iostream>
#include "subsystems/SubDriveTrain.h"

SubDriveTrain::SubDriveTrain(SubIMU * iIMU)
{

    // Initialization of the SwerveModules' location relative to the robot center
    m_frontLeftLocation = new frc::Translation2d{0.3683_m, 0.3556_m};
    m_frontRightLocation = new frc::Translation2d{0.3683_m, -0.3556_m};
    m_backLeftLocation = new frc::Translation2d{-0.3683_m, 0.3556_m};
    m_backRightLocation = new frc::Translation2d{-0.3683_m, -0.3556_m};

    // Initialization of the SwerveModules with the motor IDs
    m_frontLeftModule = new SwerveModule{DriveTrainConstants::kFrontLeftMotorID,DriveTrainConstants::kFrontLeftMotor550ID};
    m_frontRightModule = new SwerveModule{DriveTrainConstants::kFrontRightMotorID, DriveTrainConstants::kFrontRightMotor550ID};
    m_backLeftModule = new SwerveModule{DriveTrainConstants::kBackLeftMotorID, DriveTrainConstants::kBackLeftMotor550ID};
    m_backRightModule = new SwerveModule{DriveTrainConstants::kBackRightMotorID, DriveTrainConstants::kBackRightMotor550ID};

    m_frontLeftModule->setNeoInverted(true);

    visionMeasurementStdDevs = new wpi::array<double, 3>{0.7, 0.7, 99999};

    // Initialization of the IMU
    mIMU = iIMU;

    // Initialization of the swerve kinematics with the SwerveModules' location
    m_kinematics = new frc::SwerveDriveKinematics<4>{*m_frontLeftLocation, *m_frontRightLocation, *m_backLeftLocation, *m_backRightLocation};
    // Initialization of the robot's pose
    switch (StartPose)
    {
    case RougeGauche:
        m_startingRobotPose = new frc::Pose2d{units::meter_t(9.972), units::meter_t(0.769), mIMU->getRotation2d() + frc::Rotation2d(units::degree_t(180))};
        break;
    case RougeCentre:
        m_startingRobotPose = new frc::Pose2d{units::meter_t(9.972), units::meter_t(4.030), mIMU->getRotation2d() + frc::Rotation2d(units::degree_t(180))};
        break;
    case RougeDroite:
        m_startingRobotPose = new frc::Pose2d{units::meter_t(9.972), units::meter_t(7.3), mIMU->getRotation2d() + frc::Rotation2d(units::degree_t(180))};
        break;
    case BleuGauche:
        m_startingRobotPose = new frc::Pose2d{units::meter_t(8), units::meter_t(7.261), mIMU->getRotation2d()};
        break;
    case BleuCentre:
        m_startingRobotPose = new frc::Pose2d{units::meter_t(8), units::meter_t(4.010), mIMU->getRotation2d()};
        break;
    case BleuDroite:
        m_startingRobotPose = new frc::Pose2d{units::meter_t(7.58), units::meter_t(0.774), mIMU->getRotation2d()};
        break;
    case Test:
        m_startingRobotPose = new frc::Pose2d{units::meter_t(7), units::meter_t(4), mIMU->getRotation2d()};
        break;
    }

    // Initialization of the swerve pose estimator with the kinematics, the robot's rotation, an array of the SwerveModules' position, and the robot's pose
    m_poseEstimator = new frc::SwerveDrivePoseEstimator<4>{*m_kinematics, mIMU->getRotation2d(), {
                    m_frontLeftModule->getModulePosition(),
                    m_frontRightModule->getModulePosition(),
                    m_backLeftModule->getModulePosition(),
                    m_backRightModule->getModulePosition()}, *m_startingRobotPose};

    m_poseEstimator->SetVisionMeasurementStdDevs(*visionMeasurementStdDevs);

    pathplanner::AutoBuilder::configure(
      [this](){ return getPose(); }, // Robot pose supplier
      [this](frc::Pose2d pose){ resetPose(pose); }, // Method to reset odometry (will be called if your auto has a starting pose)
      [this](){ return getRobotRelativeSpeeds(); }, // ChassisSpeeds supplier. MUST BE ROBOT RELATIVE
      [this](auto speeds, auto feedforwards){ driveRobotRelative(speeds, 1); }, // Method that will drive the robot given ROBOT RELATIVE ChassisSpeeds. Also optionally outputs individual module feedforwards
      std::make_shared<pathplanner::PPHolonomicDriveController>( // PPHolonomicController is the built in path following controller for holonomic drive trains
      pathplanner::PIDConstants(PathPlannerConstants::kPTranslation, PathPlannerConstants::kITranslation, PathPlannerConstants::kDTranslation), // Translation PID constants
      pathplanner::PIDConstants(PathPlannerConstants::kPRotation, PathPlannerConstants::kIRotation, PathPlannerConstants::kDRotation) // Rotation PID constants
      ),
      config, // The robot configuration
      []() {
          // Boolean supplier that controls when the path will be mirrored for the red alliance
          // This will flip the path being followed to the red side of the field.
          // THE ORIGIN WILL REMAIN ON THE BLUE SIDE  
          return false;
      },
      this // Reference to this subsystem to set requirements
    );
}

// This method will be called once per scheduler run
void SubDriveTrain::Periodic()
{
    // Refreshing the SwerveModules' position and states
    m_frontLeftModule->refreshModule();
    m_frontRightModule->refreshModule();
    m_backLeftModule->refreshModule();
    m_backRightModule->refreshModule();

    // Update of the robot's pose with the robot's rotation and an array of the SwerveModules' position
    frc::Rotation2d gyroAngle = mIMU->getRotation2d();
    m_poseEstimator->Update(gyroAngle, {
                    m_frontLeftModule->getModulePosition(),
                    m_frontRightModule->getModulePosition(),
                    m_backLeftModule->getModulePosition(),
                    m_backRightModule->getModulePosition()});

    bool rejectUpdate = false;
    LimelightHelpers::SetRobotOrientation("", m_poseEstimator->GetEstimatedPosition().Rotation().Degrees().value(), 0, 0, 0, 0, 0);
    LimelightHelpers::SetRobotOrientation("", mIMU->getAngleYaw(), 0, 0, 0, 0, 0);
    LimelightHelpers::PoseEstimate mt2 = LimelightHelpers::getBotPoseEstimate_wpiBlue_MegaTag2("");

    if (mIMU->getRate() > 360 || mIMU->getRate() < -360)
    {
        rejectUpdate = true;
    }
    else if (mt2.tagCount == 0)
    {
        rejectUpdate = true;
    }

    if(!rejectUpdate)
    {
        m_poseEstimator->AddVisionMeasurement(mt2.pose, frc::Timer::GetFPGATimestamp());
    }
    
}
   
void SubDriveTrain::Init() {}

void SubDriveTrain::driveFieldRelative(float iX, float iY, float i0, double SpeedModulation)
{
    // Creating a ChassisSpeeds from the wanted speeds and the robot's rotation
    frc::ChassisSpeeds speeds = frc::ChassisSpeeds::FromFieldRelativeSpeeds(units::meters_per_second_t(DriveTrainConstants::kMaxSpeed) * iY,
                                                                            units::meters_per_second_t(DriveTrainConstants::kMaxSpeed) * iX,
                                                                            units::radians_per_second_t(DriveTrainConstants::kMaxSpeed0) * i0,
                                                                            mIMU->getRotation2d());

    // Transforming the ChassisSpeeds into four SwerveModuleState for each SwerveModule
    auto [fl, fr, bl, br] = m_kinematics->ToSwerveModuleStates(speeds);

    // Setting the desired state of each SwerveModule to the corresponding SwerveModuleState
    m_frontLeftModule->setDesiredState(fl, SpeedModulation);
    m_frontRightModule->setDesiredState(fr, SpeedModulation);
    m_backLeftModule->setDesiredState(bl, SpeedModulation);
    m_backRightModule->setDesiredState(br, SpeedModulation);
}

frc::Pose2d SubDriveTrain::getPose()
{
    return m_poseEstimator->GetEstimatedPosition();
}

void SubDriveTrain::resetPose(frc::Pose2d iRobotPose)
{
    m_poseEstimator->ResetPose(iRobotPose);
}

frc::ChassisSpeeds SubDriveTrain::getRobotRelativeSpeeds()
{
    // Creating directionnal speeds from the SwerveModules' state
    auto [forward, sideways, angular] = m_kinematics->ToChassisSpeeds(wpi::array<frc::SwerveModuleState, 4>{m_frontLeftModule->getModuleState(),
                                                                                                            m_frontRightModule->getModuleState(),
                                                                                                            m_backLeftModule->getModuleState(),
                                                                                                            m_backRightModule->getModuleState()});
    // Creating a ChassisSpeeds from these speeds and the robot's rotation and returning it
    frc::ChassisSpeeds robotRelativeSpeeds = frc::ChassisSpeeds::FromRobotRelativeSpeeds(forward,sideways,angular,mIMU->getRotation2d());
    return robotRelativeSpeeds;

}

void SubDriveTrain::driveRobotRelative(frc::ChassisSpeeds speeds, double SpeedModulation)
{
    // Tansforming the ChassisSpeeds into four SwerveModuleState for each SwerveModule
    auto [fl, fr, bl, br] = m_kinematics->ToSwerveModuleStates(speeds);

    // Setting the desired state of each SwerveModule to the corresponding SwerveModuleState
    m_frontLeftModule->setDesiredState(fl, SpeedModulation);
    m_frontRightModule->setDesiredState(fr, SpeedModulation);
    m_backLeftModule->setDesiredState(bl, SpeedModulation);
    m_backRightModule->setDesiredState(br, SpeedModulation);
}