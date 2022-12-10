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
constexpr int kCameraOrienteerPort = 9;
constexpr int kCanIdClimber = 1;
constexpr int kCanIdElevatorR = 3;
constexpr int kCanIdElevatorL = 4;

/// Speed for the climbers
constexpr float kSpeedUp = -0.50F; 
constexpr float kSpeedDown = 0.50F;

//hauteur max et min pour le climber
constexpr double kHeightS3 = -420;
constexpr double kHeightS2 = -270;
constexpr double kHeightS1 =-140;
constexpr double kMinHeight = 0;

constexpr float threeinch = 10; 

constexpr int kMotorL2Port = 0;
constexpr int kMotorL1Port = 1;
constexpr int kMotorR2Port = 2;
constexpr int kMotorR1Port = 3;
constexpr int kJoystickPort = 0;

constexpr float kSpeedPush = 0.40F;
constexpr float kSpeedPull = -0.20F;

constexpr double kPosOut = 14;
constexpr double kPosIn = 0;

// default PID coefficients
constexpr double kP = 2.5e-4, kI = 2.6e-6, kD = 1e-3, kIz = 0, kFF = 0.000156, kMaxOutput = 1, kMinOutput = -1;

// default smart motion coefficients
constexpr double kMaxVel = 10000, kMinVel = 0, kMaxAcc = 8000, kAllErr = 0;

// motor max RPM
constexpr double MaxRPM = 5700;