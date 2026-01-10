// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Elevator.h"

#include <rev/SparkMax.h>

Elevator::Elevator() = default;

void Up (double Speed);

void Down (double Speed);

void Elevator::Up()
{

}//aide mettre puissance 0.2

void Elevator::Down()
{

}

void Elevator::Stop()
{
    
}

// This method will be called once per scheduler run
void Elevator::Periodic() {}
