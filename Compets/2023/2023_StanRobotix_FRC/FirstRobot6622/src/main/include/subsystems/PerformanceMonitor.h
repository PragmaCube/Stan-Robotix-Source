// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <chrono>

class RobotContainer;

class PerformanceMonitor
{
public:
  PerformanceMonitor();

  void EnablePerformanceLog(bool iEnable) { mPerformanceLogEnabled = iEnable; }
  void EnableSubsystemLog(bool iEnable) { mSubsystemLogEnabled = iEnable; }
  virtual void Enable(const bool iEnable) { mIsEnabled = iEnable; }

  void Execute();

  virtual bool isFinish() { return true; };
  virtual void reset() { }

protected:
  virtual void doExecute() = 0;
  virtual std::string getName() = 0;

  bool isEnabled()          { return mIsEnabled; }
  bool isSystemLogEnabled() { return mSubsystemLogEnabled; }

  void setLogPeriodity(unsigned int iPeriod) {mLogPeriodicity = iPeriod; }

  RobotContainer * mRobotContainer = nullptr;
  
  unsigned int mLogPeriodicity = kLogPeriod_Undefined;   // Le log est pseudo-desactive par defaut
  const unsigned int kLogPeriod_100ms = 5;
  const unsigned int kLogPeriod_260ms = 13; //ce n'est pas 250 car ce n'est pas divisible par 20
  const unsigned int kLogPeriod_500ms = 25;
  const unsigned int kLogPeriod_1s = 50;
  const unsigned int kLogPeriod_2s = 100;
  const unsigned int kLogPeriod_5s = 250;
  const unsigned int kLogPeriod_10s = 1000;
  const unsigned int kLogPeriod_Undefined = 10000000;

  bool timeToDisplaySystemLog()  { return mSubsystemLogEnabled &&
                                          ((mNumberOfExecution % mLogPeriodicity) == 0); }

private:
  std::chrono::nanoseconds mMinDurationiNnS = std::chrono::nanoseconds::max();
  std::chrono::nanoseconds mMaxDurationiNnS = std::chrono::nanoseconds::min();
  std::chrono::nanoseconds mMoyDurationiNnS = std::chrono::nanoseconds::zero();
  std::chrono::nanoseconds mAccumulDurationiNnS = std::chrono::nanoseconds::zero();

  unsigned long mNumberOfExecution = 1;

  bool mPerformanceLogEnabled      = false;
  bool mIsEnabled                  = false;
  bool mSubsystemLogEnabled        = false;
};
