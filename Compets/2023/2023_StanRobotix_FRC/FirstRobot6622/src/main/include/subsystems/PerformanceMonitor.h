// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <chrono>

class PerformanceMonitor
{
public:
  PerformanceMonitor();

  void Execute();

  void EnableLog(bool iEnable) { mLog = iEnable; };

protected:
  virtual void doExecute() = 0;

  virtual std::string getName() = 0;

private:
  std::chrono::nanoseconds mMinDurationiNnS = std::chrono::nanoseconds::max();
  std::chrono::nanoseconds mMaxDurationiNnS = std::chrono::nanoseconds::min();
  std::chrono::nanoseconds mMoyDurationiNnS = std::chrono::nanoseconds::zero();
  std::chrono::nanoseconds mAccumulDurationiNnS = std::chrono::nanoseconds::zero();

  unsigned long mNumberOfExecution = 1;
  bool mLog = false;
};
