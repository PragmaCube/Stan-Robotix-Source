// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubAlgaePivot.h"
#include <cmath>


SubAlgaePivot::SubAlgaePivot(){
    mAlgaePivotMotor = new rev::spark::SparkMax{AlgaeConstants::Pivot::kMotorID,  rev::spark::SparkLowLevel::MotorType::kBrushless};
    mArmFeedForward = new frc::ArmFeedforward{AlgaeConstants::Pivot::kS, AlgaeConstants::Pivot::kG, AlgaeConstants::Pivot::kV, AlgaeConstants::Pivot::kA};
    mPIDController = new frc::PIDController{AlgaeConstants::Pivot::kP, AlgaeConstants::Pivot::kI, AlgaeConstants::Pivot::kD};
    mProfiledPIDController = new frc::ProfiledPIDController<units::radians>{AlgaeConstants::Pivot::kP, AlgaeConstants::Pivot::kI, AlgaeConstants::Pivot::kD, {}};
    mSparkMaxConfig = new rev::spark::SparkMaxConfig{};

    mSparkMaxConfig->signals.PrimaryEncoderPositionPeriodMs(5);
    mSparkMaxConfig->signals.PrimaryEncoderPositionAlwaysOn(true);
    mSparkMaxConfig->signals.PrimaryEncoderVelocityPeriodMs(5);
    mSparkMaxConfig->signals.PrimaryEncoderVelocityAlwaysOn(true);
    mSparkMaxConfig->signals.AppliedOutputPeriodMs(5);
    mSparkMaxConfig->signals.AppliedOutputAlwaysOn(true);
    mSparkMaxConfig->encoder.PositionConversionFactor(0.0125);
    mSparkMaxConfig->encoder.VelocityConversionFactor(0.0125);

    mAlgaePivotMotor->Configure(*mSparkMaxConfig, rev::spark::SparkBase::ResetMode::kNoResetSafeParameters, rev::spark::SparkBase::PersistMode::kNoPersistParameters);
    
    mMotorRelativeEncoder = new rev::spark::SparkRelativeEncoder{mAlgaePivotMotor->GetEncoder()};

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

void SubAlgaePivot::PIDPivot(double Setpoint){
    mPIDController->SetSetpoint(Setpoint);
    
    double pivotPositionRad = (mAlgaePivotMotor->GetEncoder().GetPosition() + AlgaeConstants::Pivot::kOffset) * 2 * std::numbers::pi;
    double CalculatedPID = mPIDController->Calculate((mAlgaePivotMotor->GetEncoder().GetPosition() + AlgaeConstants::Pivot::kOffset) * 2 * std::numbers::pi) * 13;

    mAlgaePivotMotor->SetVoltage(AlgaeConstants::Pivot::kG * cos(pivotPositionRad) + units::volt_t(CalculatedPID) * PIDEnable);  //  
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

void SubAlgaePivot::StayStill(){
    mAlgaePivotMotor->SetVoltage(units::volt_t(-0.75));
}

SubAlgaePivot::StatesAlgae SubAlgaePivot::GetState(){
    return mState;
}

void SubAlgaePivot::SetState(SubAlgaePivot::StatesAlgae iState){
    mState = iState;
}

void SubAlgaePivot::CounterGravity(){
    double pivotPositionRad = (mAlgaePivotMotor->GetEncoder().GetPosition() + AlgaeConstants::Pivot::kOffset) * 2 * std::numbers::pi;
    mAlgaePivotMotor->SetVoltage(AlgaeConstants::Pivot::kG * cos(pivotPositionRad));
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