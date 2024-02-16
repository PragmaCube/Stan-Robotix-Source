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
namespace EjectorConstants
{
    constexpr float kSpeedPull=1.0;
    constexpr float kSpeedPush=-1.0;
    constexpr int kId=1;
    constexpr int kInProximity = 1023;
}

namespace OperatorConstants {

constexpr int kDriverControllerPort = 0;


}  // namespace OperatorConstants

namespace JoystickBindingsConstants
{
    ////////////  PIVOT  ////////////
    constexpr int kPivotManualDown = 10;
    constexpr int kPivotManualUp = 12;

    ////////////  ASCENSEUR  ////////////
    constexpr int kAscenseurUp = 7;
    constexpr int kAscenseurMiddle = 9;
    constexpr int kAscenseurDown = 11;
    constexpr int kAscenseurManualUp = 8;
    constexpr int kAscenseurManualDown = 6;

    ////////////  EJECTOR  ////////////
    constexpr int kEjectorIn = 5;
    constexpr int kEjectorOut = 3;

    ////////////  IMU  ////////////
    constexpr int kImuReset = 1;

    ////////////  AUTOMATISATIONS  ////////////
    constexpr int kGotoTag = 2;

}

namespace DriveTrainConstants
{
    constexpr int kMotorL1Id = 2;
    constexpr int kMotorL2Id = 4;
    constexpr int kMotorR1Id = 3;
    constexpr int kMotorR2Id = 1;

    // bool driveEnabled = true;
    
} // namespace DriveTrainConstants

namespace DrivePIDConstants
{
    constexpr double kTurnP = 0.2;
    constexpr double kTurnI = 1.2;
    constexpr double kTurnD = 0.1;
}

namespace AscenseurConstants {

    constexpr int kMotorId1 = 1;
    constexpr int kMotorId2 = 3;

    constexpr double kAscenseurLimitUp = 80;
    constexpr double kAscenseurLimitMiddle = 30;
    constexpr double kAscenseurLimitDown = 0;

    constexpr double kP = 0.00004999999873689376, 
                 kI = 9.999999974752427e-7, 
                 kD = 0, 
                 kIz = 0, 
                 kFF = 0.000155999994603917, 
                 kMaxOutput = 0.5,
                 kMinOutput = -0.5;
}

namespace PivotConstants
{
    constexpr float kHeightUp = -3;
    constexpr float kHeightMiddle = 0;
    constexpr float kHeightDown = 3;
    constexpr int kMotorId = 7;

    constexpr double kP = 0.00004999999873689376, 
                 kI = 9.999999974752427e-7, 
                 kD = 0, 
                 kIz = 0, 
                 kFF = 0.000155999994603917, 
                 kMaxOutput = 0.5,
                 kMinOutput = -0.5;
} // namespace mPivotMotor

