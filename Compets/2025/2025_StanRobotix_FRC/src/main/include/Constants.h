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
    constexpr int kBackRightMotor550ID = 7; 
    constexpr int kFrontRighttMotorID = 6; 
    constexpr int kFrontRightMotor550ID = 5; 
    constexpr int kFrontLeftMotorID = 4;    
    constexpr int kFrontLeftMotor550ID = 3;
    constexpr int kBackLeftMotorID = 2; 
    constexpr int kBackLefttMotor550ID = 1;  

    namespace PIDs{
        constexpr double kP = 0.2;
        constexpr double kI = 0.0;
        constexpr double kD = 0.0;
    }
}

namespace ChainConstants {

    constexpr int kMotorID = 2;
}