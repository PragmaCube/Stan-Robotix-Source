// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <units/length.h>
#include <units/angle.h>
#include <units/velocity.h>
#include <units/voltage.h>
#include <frc/controller/ArmFeedforward.h>
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

namespace AlgaeConstants {
    namespace Pivot{
        constexpr double kP = 0.2;
        constexpr double kI = 0;
        constexpr double kD = 0;

        constexpr int kMotorID = 9;
        constexpr double kAlgaePivotSetPoint1 = 0.2;
        constexpr double kAlgaePivotSetPoint2 = -0.2;
        constexpr double kOffset = 33.6426;

        constexpr units::volt_t kS = units::volt_t(0.16695);
        constexpr units::volt_t kG = units::volt_t(0.35);
        constexpr units::unit_t<frc::ArmFeedforward::kv_unit> kV = units::unit_t<frc::ArmFeedforward::kv_unit>(5.9157E-06);
        constexpr units::unit_t<frc::ArmFeedforward::ka_unit> kA = units::unit_t<frc::ArmFeedforward::ka_unit>(2.0288E-05);
    }
}

namespace JoystickBindingsConstants{
    
    namespace Algae{
        constexpr int kPivotUp = 5; 
        constexpr int kPivotDown = 3;

        constexpr int kDynamicForward = 7;
        constexpr int kDynamicReverse = 8;
        constexpr int kQuasistaticForward = 9;
        constexpr int kQuasistaticReverse = 10;
    }
}