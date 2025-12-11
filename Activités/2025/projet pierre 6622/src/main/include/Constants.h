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

namespace PIDConstant {/*OUTPUT🕊️🕊️🕊️🕊️🕊️🕊️🕊️🕊️🕊️🕊️🕊️🕊️🕊️*/


constexpr double kPController = 1.0;
constexpr double kDController = 0.0;
constexpr double kIController = 0.0;
constexpr double kSetPointController = 90.0;



}

namespace OperatorConstants {

inline constexpr int kDriverControllerPort = 0;



}  // namespace OperatorConstants
