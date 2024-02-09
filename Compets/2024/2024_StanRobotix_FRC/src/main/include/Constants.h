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

namespace OperatorConstants {

constexpr int kDriverControllerPort = 0;


}  // namespace OperatorConstants

namespace DriveTrainConstants
{
    constexpr int kMotorL1Id = 2;
    constexpr int kMotorL2Id = 4;
    constexpr int kMotorR1Id = 3;
    constexpr int kMotorR2Id = 1;
    
} // namespace DriveTrainConstants

namespace DrivePIDConstants
{
    constexpr double kTurnP = 0.2;
    constexpr double kTurnI = 1.2;
    constexpr double kTurnD = 0.1;
}