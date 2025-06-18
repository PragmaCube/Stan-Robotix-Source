// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include <frc/controller/ProfiledPIDController.h>

#include <units/length.h>
#include <frc/util/Color.h>

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

namespace DrivingConstants {
    constexpr int joystickPort = 0;
    constexpr int pigeon2port = 1;
}

namespace JoystickBindingsConstants {
    namespace Arms {
        constexpr int kArmsUp = 3;
        constexpr int kArmsDown = 2;
    }
}

namespace DriveTrainConstants {
    /* These names are refering to the robot oriented position of the motor controllers.
    Meaning the back is generally refering to the side where the battery is held.
    These IDs should be changed if you make changes in the position of the motor controller
    or changes in the way you want the robot to be oriented. */
    constexpr int kBackRightMotorID = 6; 
    constexpr int kBackRightMotor550ID = 5; 
    constexpr int kFrontRightMotorID = 8; 
    constexpr int kFrontRightMotor550ID = 7; 
    constexpr int kFrontLeftMotorID = 2;   
    constexpr int kFrontLeftMotor550ID = 1;
    constexpr int kBackLeftMotorID = 4;
    constexpr int kBackLeftMotor550ID = 3; 


    constexpr float kSpeedCap = 0.9; // Percentage of the max speed of the swerve wheels you want to use.
    constexpr float kMaxSpeed = 1;
    constexpr double kMaxSpeed0 = std::numbers::pi; 

    constexpr double kGearRatio = 1 / 5.08;
    constexpr double kWheelPerimeter = 3 * 0.0254 * std::numbers::pi;

    namespace PIDs {
        // PID constants for the motor controllers that control the orientation of the swerve wheels. Could be tuned better.
        constexpr double kP = 3.0;
        constexpr double kI = 0.1;
        constexpr double kD = 0.05;
    }
}

namespace LEDsConstants{
    static constexpr int kLength = 40;
    constexpr units::meter_t kLedSpacing = 0.03_m;
}

namespace ArmsConstants {
    constexpr int kSparkMaxRightDeviceID = 9;
    constexpr int kSparkMaxLeftDeviceID = 10;
    constexpr double kP = 0.1;
    constexpr double kI = 0.01;
    constexpr double kD = 0;
    constexpr double kG = 0.02;
    constexpr double kOffset = 0.25;
    constexpr double gearRatio = 20.0;

    namespace Positions {
        constexpr double kUp = 1;
        constexpr double kDown = 0;
    }
}