/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/CommandGroup.h>
#include <Commands/Aligner.h>
#include <Commands/Advance.h>
#include <Commands/Turn.h>
#include <Subsystems/CentrePID.h>

class HatchAlign : public frc::CommandGroup {
 public:
  HatchAlign();
};
