// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubAlgaePivot.h"
#include <cmath>


SubAlgaePivot::SubAlgaePivot(){
    mAlgaePivotMotor = new rev::spark::SparkMax{AlgaeConstants::Pivot::kMotorID,  rev::spark::SparkLowLevel::MotorType::kBrushless};
    mMotorRelativeEncoder = new rev::spark::SparkRelativeEncoder{mAlgaePivotMotor->GetEncoder()};
    mArmFeedForward = new frc::ArmFeedforward{AlgaeConstants::Pivot::kS, AlgaeConstants::Pivot::kG, AlgaeConstants::Pivot::kV, AlgaeConstants::Pivot::kA};
    mPIDController = new frc::PIDController{AlgaeConstants::Pivot::kP, AlgaeConstants::Pivot::kI, AlgaeConstants::Pivot::kD};
    mProfiledPIDController = new frc::ProfiledPIDController<units::radians>{AlgaeConstants::Pivot::kP, AlgaeConstants::Pivot::kI, AlgaeConstants::Pivot::kD, {}};

    m_sysIdRoutine = new frc2::sysid::SysIdRoutine{
        frc2::sysid::Config{std::nullopt, std::nullopt, std::nullopt, nullptr},
        frc2::sysid::Mechanism{
            [this](units::volt_t driveVoltage) {
                ManualVoltage(driveVoltage);
            },
            [this](frc::sysid::SysIdRoutineLog* log) {
                log->Motor("Algae-Pivot")
                    .voltage(mAlgaePivotMotor->Get() *
                            frc::RobotController::GetBatteryVoltage())
                    .position(units::meter_t{mMotorRelativeEncoder->GetPosition()})
                    .velocity(units::meters_per_second_t{mMotorRelativeEncoder->GetVelocity()});
            },
            this}};
}

// This method will be called once per scheduler run
void SubAlgaePivot::Periodic() {
   // std::cout << cos((mAlgaePivotMotor->GetEncoder().GetPosition() + kOffset) / 80 * 2 * std::numbers::pi) << std::endl;
}

void SubAlgaePivot::ManualVoltage(units::volt_t iVoltage)
{
    mAlgaePivotMotor->SetVoltage(iVoltage * 0.25);
}

void SubAlgaePivot::Stop(){
    mAlgaePivotMotor->StopMotor();
}

void SubAlgaePivot::Pivot(double Setpoint){
    mPIDController->SetSetpoint(Setpoint);
    
    double pivotPositionRad = (mAlgaePivotMotor->GetEncoder().GetPosition() + kOffset) / 80 * 2 * std::numbers::pi;
    double CalculatedPID = mPIDController->Calculate((mAlgaePivotMotor->GetEncoder().GetPosition() + kOffset) / 80 * 2 * std::numbers::pi) * 13;

    mAlgaePivotMotor->SetVoltage((units::volt_t(kG * cos(pivotPositionRad))) + units::volt_t(CalculatedPID) * PIDEnable);  //  
}

bool SubAlgaePivot::AtSetPoint(){
    return mPIDController->AtSetpoint();
}

void SubAlgaePivot::SetSetPoint(double iSetPoint){
    mPIDController->SetSetpoint(iSetPoint);
}

void SubAlgaePivot::SetPIDEnable(bool iState){
    PIDEnable = iState;
}

void SubAlgaePivot::Climb(){
    mAlgaePivotMotor->SetVoltage(units::volt_t(-2.5));
}

void SubAlgaePivot::StayStill(){
    mAlgaePivotMotor->SetVoltage(units::volt_t(-0.75));
}

SubAlgaePivot::StatesAlgae SubAlgaePivot::GetState(){
    return mState;
}

void SubAlgaePivot::SetState(SubAlgaePivot::StatesAlgae iState){
    mState = iState;
}

void SubAlgaePivot::PivotUpSmooth(){
    mAlgaePivotMotor->SetVoltage(units::volt_t(0.95));
}

void SubAlgaePivot::CounterGravity(){
    double pivotPositionRad = (mAlgaePivotMotor->GetEncoder().GetPosition() + kOffset) / 80 * 2 * std::numbers::pi;
    mAlgaePivotMotor->SetVoltage(units::volt_t(kG) * cos(pivotPositionRad));
}

frc2::CommandPtr SubAlgaePivot::SysIdQuasistatic(frc2::sysid::Direction direction) {
  return m_sysIdRoutine->Quasistatic(direction);
}

frc2::CommandPtr SubAlgaePivot::SysIdDynamic(frc2::sysid::Direction direction) {
  return m_sysIdRoutine->Dynamic(direction);
}

/*
    le setpoint doit etre donné en tours, même type que le cout.
    le cout renvoi la position du pivot entre -1 et 1, avec 0 comme pivot horizontale.
    le PID devrait calculer une valeur aussi entre -1 et 1, qui se fait multiplier par 13 pour avoir une nombre utilisable de volts.
*/