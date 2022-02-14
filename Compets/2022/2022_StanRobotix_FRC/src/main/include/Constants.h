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
// À modifier si besoin
constexpr int kMotorL2Port = 0;
constexpr int kMotorL1Port = 1;
constexpr int kMotorR2Port = 2;
constexpr int kMotorR1Port = 3;

constexpr int kMotorPulley = 5;

constexpr int kJoystickPort = 0;

constexpr int kSolenoid1Port = 6;
constexpr int kSolenoid2Port = 7;

constexpr int kElevator1Port = 8;
constexpr int kElevator2Port = 9;
constexpr float speedUp = 0.35; 
constexpr float speedDown = -0.25;