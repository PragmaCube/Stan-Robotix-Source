// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <iostream>

#include <frc/TimedRobot.h>
#include <frc/motorcontrol/VictorSP.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/XboxController.h>
#include <rev/CANSparkMax.h>

#include <frc/shuffleboard/Shuffleboard.h>
#include <networktables/GenericEntry.h>
#include <networktables/NetworkTableInstance.h>
#include <frc/shuffleboard/BuiltInWidgets.h>

#include <rev/SparkMaxPIDController.h>
#include <frc/Filesystem.h>
#include <wpi/fs.h>
#include <iostream>
#include <fstream>
#include <string>

#include <frc/AddressableLED.h>

#include <units/voltage.h>
#include <units/current.h>

#include <frc/Servo.h>
#include <frc/filter/SlewRateLimiter.h>
#include <units/time.h>


class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;

  void AutonomousInit() override;
  void AutonomousPeriodic() override;

  void TeleopInit() override;
  void TeleopPeriodic() override;

  void DisabledInit() override;
  void DisabledPeriodic() override;

  void TestInit() override;
  void TestPeriodic() override;

  void SimulationInit() override;
  void SimulationPeriodic() override;

  private : 
  enum eMotors
  {
    eLeft,
    eRight
  };
  frc::VictorSP mMotors[2] = {frc::VictorSP{eLeft},frc::VictorSP{eRight}};
  frc::DifferentialDrive mDrive{mMotors[eLeft],mMotors[eRight]};

  double mDriveX;
  double mDriveY;
  frc::XboxController mController{0};
  
  // const int kPancarteId = 1;
  const int kClimbId = 3;
  const int kRGBPort = 2;
  const int kTourPort = 3;
  // rev::CANSparkMax mPancarte{kPancarteId, rev::CANSparkMaxLowLevel::MotorType::kBrushless};
  rev::CANSparkMax mClimb{kClimbId, rev::CANSparkMaxLowLevel::MotorType::kBrushless};
  rev::SparkMaxRelativeEncoder mClimbEncoder = mClimb.GetEncoder(); 
  rev::SparkMaxPIDController mClimbPid = mClimb.GetPIDController();



  nt::GenericEntry* mSetpoint1;
  nt::GenericEntry* mSetpoint2;
  nt::GenericEntry* mClimberEnabled;
  nt::GenericEntry* mIntensity;
  nt::GenericEntry* mPosition;
  nt::GenericEntry* mIsCalibrating;


  int mSetpoints[2] = {0, -17};
  bool mIsClimberEnabled = true;

  frc::AddressableLED mLedStrip{kRGBPort};
  long int mHSVCounter = 0;
  static const int kLedLenght = 32;
  static const int kTourLenght = 223;
  const int kActualTourLenght = 171;
  frc::AddressableLED::LEDData mLedData[kTourLenght + kLedLenght];
  frc::Color8Bit mColor;
  double mClimbMotionSmoothing = 0.0;

  enum eState
  {
    eIdle,
    eClimbing,
    eUp
  };

  eState mState = eIdle;
  
  //Definitions de couleurs predefinies
  const frc::AddressableLED::LEDData kRed    {255, 0  , 0  };
  const frc::AddressableLED::LEDData kGreen  {0  , 255, 0  };
  const frc::AddressableLED::LEDData kBlue   {0  ,   0, 255};
  const frc::AddressableLED::LEDData kAmber  {255, 165, 0  };
  const frc::AddressableLED::LEDData kPurple {140, 200, 0  };
  const frc::AddressableLED::LEDData kOrange {255, 191, 0  };
  const frc::AddressableLED::LEDData kGold   {255, 215, 0  };
  const frc::AddressableLED::LEDData kYellow {255, 255, 0  };
  const frc::AddressableLED::LEDData kBlack  {0  ,   0, 0  };
  const frc::AddressableLED::LEDData kWhite  {255, 255, 255};
  const frc::AddressableLED::LEDData kMagenta{255,   0, 255};

  double mClimbZero; //Position relative du "zero" absolu

  double mMotionSmoothedDrive[2] = {0,0};
  const double kMotionSmoothingDrivePart = 0.05;
  const double kMaxStickDelta = 0.25;

  frc::Servo mServo{3};

  units::second_t kRampTime = 2_s;
  frc::SlewRateLimiter<units::scalar> mLeftFilter{1.0 / kRampTime};
  frc::SlewRateLimiter<units::scalar> mRightFilter{1.0 / kRampTime};

};
