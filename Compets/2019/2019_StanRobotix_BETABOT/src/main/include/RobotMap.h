/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
constexpr int kSolenoid0 = 0;
constexpr int kSolenoid1 = 1;
// solenoid0 est a la base, solenoid1 est au bout du piston

constexpr int kMotorL1 = 3;
constexpr int kMotorL2 = 2;
constexpr int kMotorR1 = 1;
constexpr int kMotorR2 = 0;

constexpr int kJoystick = 0;
constexpr int kJoystickX = 0;
constexpr int kJoystickY = 1;
constexpr int kJoystickZ = 2;
constexpr int kJoystickSlider = 3;
constexpr int kJoystickButton1 = 1;
constexpr int kJoystickButton2 = 2;

constexpr int kCaptDist = 0;
constexpr int kCaptDist2 = 1;
constexpr double VoltToFootDistCapt = 3.5606;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int kRangeFinderPort = 1;
// constexpr int kRangeFinderModule = 1;
