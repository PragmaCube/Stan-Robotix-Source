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

    constexpr float kSpeedCap = 0.9; 
    constexpr float kMaxSpeed = 1;
    constexpr double kMaxSpeed0 = std::numbers::pi;
    constexpr double kGearRatio = 1 / 5.08;
    constexpr double kWheelPerimeter = 3 * 0.0254 * std::numbers::pi;

    namespace PIDs{
        // constexpr double kP = 4.0; Garder la valeure
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

    constexpr double kStartingPoseX = 8.0;
    constexpr double kStartingPoseY = 0.789;
}

namespace ChainConstants {

    constexpr int kMotorID = 2;
}

namespace AlgaeConstants {
    namespace Pivot{
        constexpr double kP = 0.5;
        constexpr double kI = 0.07;
        constexpr double kD = 0;

        constexpr int kMotorID = 9;
        constexpr double kAlgaePivotSetPoint1 = 0.2;
        constexpr double kAlgaePivotSetPoint2 = -0.2;
    }

    namespace Intake{
        constexpr int kMotorID = 10;

        constexpr double kAlgaeIntakeSpeed = 0.2; //temporaire
        constexpr double kNegativeAlgaeIntakeSpeed = -0.2; //temporaire

        constexpr double kG = 0.19; 
        constexpr double kS = kG + 0.05;
    }
}


namespace CoralConstants {
    namespace Pivot{
        constexpr double kP = 0.5;
        constexpr double kI = 0.07;
        constexpr double kD = 0;

        constexpr int kMotorID = 11;
        constexpr double kCoralPivotSetPoint1 = 0.2;
        constexpr double kCoralPivotSetPoint2 = -0.2;
        constexpr double kG = 0;
    }
    
    namespace Intake{
        constexpr int kMotorID = 12;
    }
}

namespace ReefConstants {
    namespace Pivot{
        constexpr double kP = 0.5;
        constexpr double kI = 0.07;
        constexpr double kD = 0;

        constexpr int kPivotMotorID = 16;
        constexpr double kReefPivotSetPoint1 = 0.2;
        constexpr double kReefPivotSetPoint2 = -0.2;
        constexpr double kG = 0;
    }

    namespace Intake{
        constexpr int kIntakeMotorID = 13;
    }
}

namespace CommandConstants {
    constexpr int kIterationsGoal = 49;
}

namespace JoystickBindingsConstants{
    // constexpr int kResetIMU = 12;

    namespace Algae{
        constexpr int kPivotUp = 5; 
        constexpr int kPivotDown = 3;

        constexpr int kManualIn = 9;
            constexpr int kManualPivotUp = 10;
    }
    
    namespace Coral{
        constexpr int kPivotUp = 6;
        constexpr int kPivotDown = 4;

        constexpr int kManualIn = 7;
    }
    constexpr int kGoToTag = 2;

    constexpr int kClimb = 11;

    constexpr int kResetIMU = 8;

    constexpr int kAlgaeIntakeInCmd = 20; // Mauvais IDs pour rendre les commandes inactives pour le moment
    constexpr int kAlgaeIntakeOutCmd = 21; // Mauvais IDs pour rendre les commandes inactives pour le moment

}