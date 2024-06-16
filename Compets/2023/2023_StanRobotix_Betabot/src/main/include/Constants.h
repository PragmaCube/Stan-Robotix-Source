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


namespace EjectorConstants
{
    constexpr int kCanIdElevator = 3;
    constexpr float kSpeedPush = 1.0F;
    constexpr float kSpeedPull = -1.0F; 
} // namespace EjectorConstants

namespace ArmConstants
{
    constexpr int kMotorId = 4;
    constexpr float motorSpeed = 0.15; 
    constexpr float kArmLimitUp = 2;
    constexpr float kArmLimitDown = 0;

    constexpr double kP = 0.00004999999873689376, 
                 kI = 9.999999974752427e-7, 
                 kD = 0, 
                 kIz = 0, 
                 kFF = 0.000155999994603917, 
                 kMaxOutput = 0.5,
                 kMinOutput = -0.5;
} // namespace ArmConstants

namespace DriveTrainConstants
{
    constexpr int kArmCanId = 4;
    constexpr int kPositionUp = 400;

    constexpr int kPositionDown = 0;
}

namespace EjectorConstants

{
    constexpr int kEjectorCanId = 3;
}

namespace DriveTrainConstants
{
    constexpr int kMotorL1Id = 1;
    constexpr int kMotorL2Id = 3;
    constexpr int kMotorR1Id = 2;
    constexpr int kMotorR2Id = 4;
    
} // namespace DriveTrainConstants

