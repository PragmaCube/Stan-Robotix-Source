// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "commands/GoToTag.h"

// NOTE:  Consider using this command inline, rather than writing a subclass.
// For more information, see:
// https://docs.wpilib.org/en/stable/docs/software/commandbased/convenience-features.html
GoToTag::GoToTag()
    : CommandHelper{frc2::PIDController{0.001, 0, 0},
                    // This should return the measurement
                    [] { return LimelightHelpers::getTX(""); },
                    // This should return the setpoint (can also be a constant)
                    [] { return 0; },
                    // This uses the output
                    [this](double output) {
                      // Use the output here
                      /*on appelle le drivetrain*/
                      GetController().SetPID(mCoefP->GetDouble(0),mCoefI->GetDouble(0),mCoefD->GetDouble(0));
                    }} {
                      mCoefP = frc::Shuffleboard::GetTab("GoToTab")
                                                  .Add("Coef P", 0.001)
                                                  .WithWidget(frc::BuiltInWidgets::kTextView)
                                                  .GetEntry();

                      mCoefI = frc::Shuffleboard::GetTab("GoToTab")
                                                  .Add("Coef I", 0)
                                                  .WithWidget(frc::BuiltInWidgets::kTextView)
                                                  .GetEntry();

                      mCoefD = frc::Shuffleboard::GetTab("GoToTab")
                                                  .Add("Coef D", 0)
                                                  .WithWidget(frc::BuiltInWidgets::kTextView)
                                                  .GetEntry();
                    }

// Returns true when the command should end.
bool GoToTag::IsFinished() {
  return GetController().AtSetpoint();
}
