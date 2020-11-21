/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <string>

static std::string kCameraIP = "10.66.22.20";
static std::string kCameraName = "camera0";
constexpr int axisCamWidth = 480;
constexpr int axisCamHeight = 360;


constexpr int kVentouse0 = 0;
constexpr int kVentouse1 = 1;
constexpr int kHatchPiston0 = 2;
constexpr int kHatchPiston1 = 3;


constexpr int kMotorLeft1 = 1;
constexpr int kMotorLeft2 = 2;
constexpr int kMotorRight1 = 3;
constexpr int kMotorRight2 = 0;
constexpr int SparkMotor = 1;
constexpr int kActuator = 0;


constexpr int kJoystick = 0;
constexpr int kJoystickLeft = 1;
constexpr int kJoystickRight = 5;
constexpr int kJoystickLeftTrigger = 2;
constexpr int kJoystickRightTrigger = 3;

constexpr int kAButton = 1;
constexpr int kBButton = 2; 
constexpr int kXButton = 3;
constexpr int kYButton = 4;
constexpr int kLBButton = 5; 
constexpr int kRBButton = 6;
constexpr int kStartButton = 7;


constexpr int kGyro = 0;  
constexpr int kGyroSensitivity = 3;

constexpr double kCircumference = 18.8495559;

constexpr double VoltToFootDistCapt = 3.5606;

constexpr double kConversionAccelerometer = 385.82698;


/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// constexpr int kLeftMotor = 1;
// constexpr int kRightMotor = 2;

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// constexpr int kRangeFinderPort = 1;
// constexpr int kRangeFinderModule = 1;
