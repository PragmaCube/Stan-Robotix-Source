/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/CommandGroup.h>
#include <commands/PistonPulse.h>
#include <commands/Advance.h>
#include <commands/Wait.h>
#include <commands/KeepAdvance.h>


class Autonome : public frc::CommandGroup {
 public:
  Autonome();
};
