// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <units/length.h>
#include <units/angle.h>
#include <units/velocity.h>
#include <units/voltage.h>
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

namespace PathPlannerConstants {
    constexpr double kPTranslation = 5.0;
    constexpr double kITranslation = 0.0;
    constexpr double kDTranslation = 0.0;
    constexpr double kPRotation = 5.0;
    constexpr double kIRotation = 0.0;
    constexpr double kDRotation = 0.0;
<<<<<<< HEAD:Compets/2025/2025_StanRobotix_FRC/src/main/include/Constants.h
}

namespace AlgaeConstants {
    namespace Pivot {
        constexpr int kMotorID = 9;

        // PID constants for the Pivot.
        constexpr double kP = 0.2;
        constexpr double kI = 0;
        constexpr double kD = 0;

        // Setpoints for the PID of the pivot.
        constexpr double kPositionUp = 0.2;
        constexpr double kPositionDown = -0.2;
        
        // Voltage used to counter the force of gravity.
        constexpr units::volt_t kG = units::volt_t(0.35);

        // Voltage needed to elevate the robot during the climb phase.
        constexpr units::volt_t ClimbRiseVoltage = units::volt_t(-2.5);

        // Voltage needed to make the pivot stay in the same position while supporting the robots weight.
        constexpr units::volt_t ClimbNeutralVoltage = units::volt_t(-0.75);

        // Voltage used to manually make the pivot go up after the climbing phase.
        constexpr units::volt_t PivotUpVoltage = units::volt_t(0.95);

        // Offset used to make the pivot's horizontal position the zero.
        constexpr double kOffset = 33.6426;

        constexpr double gearRatio = 80;
    }

    namespace Intake {
        constexpr int kMotorID = 10;

        constexpr double kIntakeOutput = 0.2; //temporaire
        constexpr double kOuttakeOutput = -0.2; //temporaire
    }
}


namespace CoralConstants {
    namespace Pivot {
        constexpr int kMotorID = 11;

        // PID constants for the pivot.
        constexpr double kP = 0.2;
        constexpr double kI = 0.001;
        constexpr double kD = 0;

        // Setpoints for the PID of the pivot.
        constexpr double kPositionUp = 0.2;
        constexpr double kPositionDown = -0.2;
        
        // Voltage used to counter the force of gravity.
        constexpr units::volt_t kG = units::volt_t(-1.38);

        // Offset used to make the pivot's horizontal position the zero.
        constexpr double kOffset =  -4.667;
    }
    
    namespace Intake {
        constexpr int kMotorID = 12;
    }
}

namespace ReefConstants {
    namespace Pivot {
        constexpr int kMotorID = 16;

        // PID constants for the ReefPivot/Gabriel.
        constexpr double kP = 0.14;
        constexpr double kI = 0;
        constexpr double kD = 0;

        // Setpoints for the PID of the pivot.
        constexpr double kPositionUp = 0.2;
        constexpr double kPositionDown = -0.2;
        
        // Voltage used to counter the force of gravity.
        constexpr double kG = 0.27;

        // Offset used to make the pivot's horizontal position the zero.
        constexpr double kOffset = 5.27;
    }
}

namespace JoystickBindingsConstants{
    namespace Algae {
        constexpr int kPivotUp = 5; 
        constexpr int kPivotDown = 3;

        constexpr int kManualIn = 9; // Manual just means that you need to keep the button pressed for the command to stay active.
        constexpr int kManualPivotUp = 10; // Idem.
    }
    
    namespace Coral {
        constexpr int kPivotUp = 6;
        constexpr int kPivotDown = 4;

        constexpr int kManualIn = 7; // Manual just means that you need to keep the button pressed for the command to stay active.
    }
=======

    constexpr double kStartingPoseX = 8.0;
    constexpr double kStartingPoseY = 0.789;
}

namespace IMUConstants {
    constexpr int kCanID = 1;
}

namespace UltrasonicConstants {
    constexpr int kUltrasonicChannel = 0;
    constexpr double kSecondsToCm = 100.0;
}

namespace Vision {
    namespace GoToAlgae {
        constexpr double kP = 0.1;
        constexpr double kI = 0;
        constexpr double kD = 0;
        constexpr double kError = 1;
    }
}

namespace JoystickBindingsConstants{
>>>>>>> origin/master:Activités/2025/PhotonVision_RnD/src/main/include/Constants.h
    constexpr int kGoToTag = 2;

    constexpr int kResetIMU = 8;
}