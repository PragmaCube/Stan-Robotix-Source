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

inline constexpr int kDriverControllerPort = 0;

}  // namespace OperatorConstants


namespace DriveTrainConstants {
    constexpr int kBackRightMotorID = 8; 
    constexpr int kBackRightMotor550ID = 1; 
    constexpr int kFrontRighttMotorID = 4; 
    constexpr int kFrontRightMotor550ID = 3; 
    constexpr int kFrontLeftMotorID = 6;   
    constexpr int kFrontLeftMotor550ID = 5;
    constexpr int kBackLeftMotorID = 2;
    constexpr int kBackLefttMotor550ID = 7; 

    constexpr float speedCap = 0.2; 

    namespace PIDs{
        constexpr double kP = 4.0;
        constexpr double kI = 0.1;
        constexpr double kD = 0.05;
    }
}

namespace ChainConstants {

    constexpr int kMotorID = 2;
}

namespace PivotConstants {
    constexpr double kP = 1;
    constexpr double kI = 0;
    constexpr double kD = 0;

    constexpr int moteurPivot = 1;
    constexpr double pivotSetPoint1 = 0.5;
    constexpr double pivotSetPoint2 = 0;
}

namespace JoystickButtons{
    constexpr int PivotUpCmd = 1; // il faut changer
    constexpr int PivotDownCmd = 2; // il faut changer
    constexpr int SubPivotStart = 3; // il faut changer
    constexpr int SubPivotStop = 4; // il faut changer
}