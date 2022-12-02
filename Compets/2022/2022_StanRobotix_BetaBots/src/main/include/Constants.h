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
constexpr int kCanIdClimber = 1;constexpr int kCanIdElevatorR = 1;
constexpr int kCanIdElevatorL = 4;

/// Speed for the climbers
constexpr float kSpeedUp = 0.25F; 
constexpr float kSpeedDown = -0.20F;

//hauteur max et min pour le climber
constexpr float kHeightS3 = 200;
constexpr float kHeightS2 = 132;
constexpr float kHeightS1 = 66;
constexpr float kMinHeight = 0;

constexpr float threeinch = 10; 

constexpr int kMotorL2Port = 0;
constexpr int kMotorL1Port = 1;
constexpr int kMotorR2Port = 2;
constexpr int kMotorR1Port = 3;
constexpr int kJoystickPort = 0;

constexpr float kSpeedPush = 0.40F;
constexpr float kSpeedPull = -0.20F; 