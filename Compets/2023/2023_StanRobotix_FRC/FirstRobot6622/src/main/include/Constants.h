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
// TODO: coef a changer selon les differents parametres du sol
constexpr double kCoeffFriction = 1.02;  

///////////////////////////////////////////////////////
// Drive Train
constexpr int kMotorL2Port = 0;
constexpr int kMotorL1Port = 1;
constexpr int kMotorR2Port = 2;
constexpr int kMotorR1Port = 3;

///////////////////////////////////////////////////////
// Ultra son 
constexpr int kUltrasonicDIO = 0;

///////////////////////////////////////////////////////
// Joystick
constexpr int kJoystickPort = 0;

///////////////////////////////////////////////////////
// Activation des logs
constexpr int  kLogUltrason_Nb = 5;             // TODO: ralentir les logs pour le Ultra-son

constexpr bool kLogPerf_UltrasonEnable = false;
constexpr bool kLogPerf_ImuEnable = true;

constexpr bool kLogIMU = true;
constexpr bool kLogDrivetrain = true;