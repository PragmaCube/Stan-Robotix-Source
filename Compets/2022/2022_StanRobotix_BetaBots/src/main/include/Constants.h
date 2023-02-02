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
// IMU
constexpr int kNumberOfSamples = 3;

///////////////////////////////////////////////////////
// Camera
constexpr int kCameraOrienteerPort = 9;
constexpr int kCanIdClimber = 1;
constexpr int kCanIdElevatorR = 3;
constexpr int kCanIdElevatorL = 4;

///////////////////////////////////////////////////////
/// Speed for the climbers
constexpr float kSpeedUp = -0.50F; 
constexpr float kSpeedDown = 0.50F;
//hauteur max et min pour le climber
constexpr double kHeightS3 = -360;
constexpr double kHeightS2 = -220;
constexpr double kHeightS1 =-80;
constexpr double kMinHeight = 0;
// TODO: coef a changer selon les differents parametres du sol
constexpr double kCoeffFriction = 1.02;  

///////////////////////////////////////////////////////
// Drive Train
constexpr int kMotorL2Port = 0;
constexpr int kMotorL1Port = 1;
constexpr int kMotorR2Port = 2;
constexpr int kMotorR1Port = 3;

///////////////////////////////////////////////////////
// Joystick
constexpr int kJoystickPort = 0;

///////////////////////////////////////////////////////
// Position rentree et sortie pour l'ejector
constexpr double kPosOut = 18;
constexpr double kPosIn = 0;
// default PID coefficients for ejector
constexpr double kP = 2.6e-4, 
                 kI = 2.8e-6, 
                 kD = 1e-3, 
                 kIz = 0, 
                 kFF = 0.000156, 
                 kMaxOutput = 1, 
                 kMinOutput = -1;
