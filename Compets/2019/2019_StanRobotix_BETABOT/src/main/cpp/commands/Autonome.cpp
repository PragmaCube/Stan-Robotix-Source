/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Autonome.h"

Autonome::Autonome() {
  // AddSequential(new Advance(1));
  AddSequential(new KeepAdvance());
  AddSequential(new Wait(1.0));
  AddSequential(new PistonPulse());
  AddSequential(new Advance(6));
  // En vrai compet : new Advance(8);
}
