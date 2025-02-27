// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <units/length.h>
#include <units/angle.h>
#include <units/velocity.h>
#include <numbers>

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
    constexpr int kBackRightMotorID = 6; 
    constexpr int kBackRightMotor550ID = 5; 
    constexpr int kFrontRightMotorID = 8; 
    constexpr int kFrontRightMotor550ID = 7; 
    constexpr int kFrontLeftMotorID = 2;   
    constexpr int kFrontLeftMotor550ID = 1;
    constexpr int kBackLeftMotorID = 4;
    constexpr int kBackLeftMotor550ID = 3; 

    constexpr float kSpeedCap = 0.2; 
    constexpr float kMaxSpeed = 1;
    constexpr double kMaxSpeed0 = std::numbers::pi;
    constexpr double kGearRatio = 1 / 5.08;
    constexpr double kWheelPerimeter = 3 * 0.0254 * std::numbers::pi;

    namespace PIDs{
        constexpr double kP = 4;
        constexpr double kI = 0.1;
        constexpr double kD = 0.05;
    }

}

namespace PathPlannerConstants {
    constexpr double kPTranslation = 5.0;
    constexpr double kITranslation = 0.0;
    constexpr double kDTranslation = 0.0;
    constexpr double kPRotation = 5.0;
    constexpr double kIRotation = 0.0;
    constexpr double kDRotation = 0.0;

    constexpr double kStartingPoseX = 0;
    constexpr double kStartingPoseY = 0;
}

namespace ChainConstants {

    constexpr int kMotorID = 2;
}