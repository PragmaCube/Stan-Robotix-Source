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

namespace DrivingConstants {

inline constexpr int kDriverControllerPort = 0;

constexpr int motor1port = 1;
constexpr int motor2port = 2;
constexpr int motor3port = 3;
constexpr int motor4port = 4;
constexpr int pigeon2port = 5;
constexpr int joystickPort = 0;
}  // namespace OperatorConstants

namespace PIDConstants {
    
    constexpr double kTurnP = 1;
    constexpr double kTurnI = 0;
    constexpr double kTurnD = 0;

}

