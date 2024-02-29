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
    constexpr float kSpeedIn = -0.3;
    constexpr float kSpeedOutUp = 0.55;
    constexpr float kSpeedOutDown = -0.4;
    constexpr int kId = 4;
    constexpr int kEjectorInTime = 1;
    constexpr int kEjectorOutDownTime = 1;
}

namespace OperatorConstants {

constexpr int kDriverControllerPort = 0;

}  // namespace OperatorConstants

namespace JoystickBindingsConstants
{
    ////////////  PIVOT  ////////////
    constexpr int kPivotDown = 11;
    constexpr int kPivotUp = 12;

    ////////////  ASCENSEUR  ////////////
    constexpr int kAscenseurUp = 8;
    // constexpr int kAscenseurMiddle = 9;
    constexpr int kAscenseurDown = 7;
    // constexpr int kAscenseurManualUp = 6;
    // constexpr int kAscenseurManualDown = 4;

    ////////////  EJECTOR  ////////////
    constexpr int kEjectorIn = 1;
    constexpr int kEjectorOutUp = 10;
    constexpr int kEjectorOutDown = 1; 

    ////////////  IMU  ////////////
    constexpr int kImuReset = 9;

    ////////////  AUTOMATISATIONS  ////////////
    constexpr int kGotoTag = 2;
    constexpr int kAmplificator = 6;
    constexpr int kPickup = 4;
    constexpr int kPosStorage = 3;
}

namespace DriveTrainConstants
{
    constexpr int kMotorL1Id = 2;
    constexpr int kMotorL2Id = 4;
    constexpr int kMotorR1Id = 3;
    constexpr int kMotorR2Id = 1;

    // bool driveEnabled = true;
    
}

namespace DrivePIDConstants
{
    constexpr double kTurnP = 0.2;
    constexpr double kTurnI = 1.2;
    constexpr double kTurnD = 0.1;
}

namespace AscenseurConstants {

    constexpr int kMotorId1 = 1;
    constexpr int kMotorId2 = 3;

    constexpr double kAscenseurLimitUp = 82 - 83;
    constexpr double kAscenseurLimitMiddle = 55 - 83;
    constexpr double kAscenseurLimitDown = 0 - 83 ;

    constexpr double kP = 0.00009999999873689376, 
                 kI = 19.999999974752427e-7,
                 kD = 0, 
                 kIz = 0, 
                 kFF = 0.000155999994603917, 
                 kMaxOutput = 1,
                 kMinOutput = -1;
}

namespace PivotConstants
{
    constexpr float kHeightUp = -16 - 9.643;
    constexpr float kHeightMiddle = -10 - 9.643;
    constexpr float kHeightDown = -0.5 - 9.643;
    constexpr int kMotorId = 7;

    constexpr double kP = 0.00004999999873689376, 
                 kI = 9.999999974752427e-7, 
                 kD = 0, 
                 kIz = 0, 
                 kFF = 0.000155999994603917, 
                 kMaxOutput = 0.5,
                 kMinOutput = -0.5;
} // namespace mPivotMotor

namespace AvancerConstants
{
    constexpr double Vitesse = 0.7;
}