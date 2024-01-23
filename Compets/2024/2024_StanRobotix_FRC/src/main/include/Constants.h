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

namespace AscenseurConstants {

    constexpr int kMotorId1 = 5;
    constexpr int kMotorId2 = 6;

    constexpr double kAscenseurLimitUp = 8;
    constexpr double kAscenseurLimitMiddle = 5;
    constexpr double kAscenseurLimitDown = 0;

    constexpr double kP = 0.00004999999873689376, 
                 kI = 9.999999974752427e-7, 
                 kD = 0, 
                 kIz = 0, 
                 kFF = 0.000155999994603917, 
                 kMaxOutput = 0.5,
                 kMinOutput = -0.5;
}