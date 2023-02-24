// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

/**
 * The Constants header provides a convenient place for teams to hold robot-wide
 * numerical or boolean constants.  This should not be used for any other
 * purpose.
 *
 * It is generally a good idea to place constants into subsystem- or
 * command-specific namespaces within this header, which can then be used where
 * they are needed.
 */

///////////////////////////////////////////////////////
// Activation indépendante des modules

#define FRC_ROBOT
#ifdef FRC_ROBOT

constexpr bool kDriveTrainEnabled = true;
constexpr bool kColorDetectionEnabled = false;
constexpr bool kContactDetectionEnable = false;
constexpr bool kElevatorEnabled = false;
constexpr bool kImuEnabled = false;
constexpr bool kLimelightEnabled = false;
constexpr bool kPneumaticEnabled = false;
constexpr bool kUltrasonEnable = false;

#else

constexpr bool kDriveTrainEnabled = false;
constexpr bool kColorDetectionEnabled = false;
constexpr bool kContactDetectionEnable = false;
constexpr bool kElevatorEnabled = false;
constexpr bool kImuEnabled = false;
constexpr bool kLimelightEnabled = true;
constexpr bool kPneumaticEnabled = false;
constexpr bool kUltrasonEnable = false;

#endif

///////////////////////////////////////////////////////
// IMU
constexpr int kNumberOfSamples = 3;

///////////////////////////////////////////////////////
// Drive Train
constexpr int kMotorL2Port = 0;
constexpr int kMotorL1Port = 1;
constexpr int kMotorR2Port = 2;
constexpr int kMotorR1Port = 3;

///////////////////////////////////////////////////////
// Pneumatic

///////////////////////////////////////////////////////
// Moteurs assenseur. 
constexpr int    kCanIdElevatorR = 4;   //Valeurs temporaires, à changer si besoin 
constexpr int    kCanIdElevatorL = 1; 
constexpr double kHeightS2 = -220; // valeurs arbitraires (certaines de betabot), faire des tests pour trouver les bonnes valeurs
constexpr double kHeightS1 =-80;
constexpr double kMinHeight = 0;

// default PID coefficients for ejector
constexpr double kP = 2.7e-4, 
                 kI = 2.7e-6, 
                 kD = 5e-4, 
                 kIz = 0, 
                 kFF = 0.000156, 
                 kMaxOutput = 1, 
                 kMinOutput = -1;

///////////////////////////////////////////////////////
// Ultra son 
constexpr int   kUltrasonicDIO = 0;



///////////////////////////////////////////////////////
// Contact
//                                      #0     #1     #2     #3     #4     #5     #6     #7     #8     #9    
constexpr bool kContactEnable[10] = {false, false, false, false, false, false, false, false, false, false} ;
constexpr int kContactDetectionDIO=0;

///////////////////////////////////////////////////////
// Joystick
constexpr int   kJoystickPort = 0;

///////////////////////////////////////////////////////
// Pneumatic
constexpr int   kSolenoid1Port = 1;
constexpr int   kSolenoid2Port = 0;

///////////////////////////////////////////////////////
// Activation des logs

constexpr bool kLogPerf_UltrasonEnable = false;
constexpr bool kLogPerf_ImuEnable = false;
constexpr bool kLogPerf_LimelightEnable = false;

constexpr bool kLogIMU = false;
constexpr bool kLogDrivetrain = false;
constexpr bool kLogLimelight = true;
constexpr bool kLogColorDetection = false;
constexpr bool kLogContactDetection = false;