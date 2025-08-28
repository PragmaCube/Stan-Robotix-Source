


#include "subsystems/SubDrivetrain.h"

SubDrivetrain::SubDrivetrain(){
    mMotorR1Controller.SetInverted(true);
    mMotorR2Controller.SetInverted(true);
}

// This method will be called once per scheduler run
void SubDrivetrain::Periodic() {}
void SubDrivetrain::Drive(double xSpeed, double ySpeed, double zRotation, frc::Rotation2d gyroAngle) {
    mRobotDrive.DriveCartesian(xSpeed, ySpeed, zRotation, gyroAngle);
}