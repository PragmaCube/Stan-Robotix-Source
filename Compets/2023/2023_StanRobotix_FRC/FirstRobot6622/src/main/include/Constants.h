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
constexpr bool kElevatorEnabled = true;
constexpr bool kGamePieceHandlerEnabled = false;
constexpr bool kIMUEnabled = true;
constexpr bool kLimelightEnabled = true;
constexpr bool kPneumaticEnabled = true;
constexpr bool kUltrasonEnable = false;

#else

constexpr bool kDriveTrainEnabled = false;
constexpr bool kColorDetectionEnabled = false;
constexpr bool kContactDetectionEnable = false;
constexpr bool kElevatorEnabled = false;
constexpr bool kGamePieceHandlerEnabled = false;
constexpr bool kIMUEnabled = false;
constexpr bool kLimelightEnabled = false;
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
// Moteurs GamePieceHandler 
constexpr int    kCanIdGamePieceHandlerR = 7;   //Valeurs temporaires, à changer si besoin 
constexpr int    kCanIdGamePieceHandlerL = 8; 

///////////////////////////////////////////////////////
// Moteurs assenseur. 
constexpr int    kCanIdElevatorR = 3;   //Valeurs temporaires, à changer si besoin 
constexpr int    kCanIdElevatorL = 1; 
constexpr double kHeightS2       = -753.0; // valeurs arbitraires (certaines de betabot), faire des tests pour trouver les bonnes valeurs
constexpr double kHeightS1       = -753.0/2.0;
constexpr double kMinHeight      = 0;

// default PID coefficients for ejector
constexpr double kP = 2.7e-4, 
                 kI = 2.5e-6, 
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
// Activation des logs de performance
constexpr bool kLogPerf_AutoConeHighEnable = false;
constexpr bool kLogPerf_AutoConeLowEnable = false;
constexpr bool kLogPerf_AutoChargeEnable = false;
constexpr bool kLogPerf_DrivetrainEnable = false;
constexpr bool kLogPerf_IMUEnable = false;
constexpr bool kLogPerf_LimelightEnable = false;
constexpr bool kLogPerf_ManualPilotEnable = false;
constexpr bool kLogPerf_UltrasonEnable = false;
constexpr bool kLogPerf_ElevatorEnable = false;
constexpr bool kLogPerf_PneumaticEnable = true;
constexpr bool kLogPerf_AutoFinalStabilisationEnable = false;
constexpr bool kLogPerf_GamePieceHandlerEnable = false;
constexpr bool kLogPerfContactDetection = false;
constexpr bool kLogPerf_AutoFollowTagEnable = false;
constexpr bool kLogPerf_AutoFollowTapeEnable = false;
// AJOUT COMMANDE AUTOMATISEE


///////////////////////////////////////////////////////
// Activation des logs de subsytems
constexpr bool kLogIMU = false;
constexpr bool kLogElevator = true;
constexpr bool kLogDrivetrain = false;
constexpr bool kLogLimelight = true;
constexpr bool kLogColorDetection = false;
constexpr bool kLogContactDetection = false;
constexpr bool kLogPilotInterface = false;
constexpr bool kLogAutoConeHighEnable = false;
constexpr bool kLogAutoConeLowEnable = false;
constexpr bool kLogAutoFollowTagEnable = false;
constexpr bool kLogAutoFollowTapeEnable = false;
constexpr bool kLogChargeUpFinalEnable = false;
constexpr bool kLogManualEnable = false;
constexpr bool kLogPneumatic = true;
constexpr bool kLogAutoFinalStabilisationEnable = false;
constexpr bool kLogGamePieceHandler = false;
constexpr bool kLogUltrason = false;

// AJOUT COMMANDE AUTOMATISEE
