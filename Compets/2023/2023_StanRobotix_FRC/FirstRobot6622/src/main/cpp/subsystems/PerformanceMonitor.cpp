#include "subsystems/PerformanceMonitor.h"

#include <iostream>

PerformanceMonitor::PerformanceMonitor()
{
}

void PerformanceMonitor::Execute()
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    doExecute();

    if (mPerformanceLogEnabled && (mNumberOfExecution % mLogPeriodicity) == 0)
    {
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

        // Calcul des statistiques
        std::chrono::nanoseconds wNewDuration = end - begin;
        mAccumulDurationiNnS += wNewDuration;
        if (wNewDuration < mMinDurationiNnS)
        {
            mMinDurationiNnS = wNewDuration;
        }
        else if (wNewDuration > mMaxDurationiNnS)
        {
            mMaxDurationiNnS = wNewDuration;
        }
        mMoyDurationiNnS = mAccumulDurationiNnS / mNumberOfExecution;

        //    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "[ns]" << std::endl;
        std::cout << "Statistics for " << getName() << std::endl
                  << "    NewDuration = " << std::chrono::duration_cast<std::chrono::microseconds>(wNewDuration).count() << "[µs]" << std::endl
                  << "    MinDurationiNnS = " << std::chrono::duration_cast<std::chrono::microseconds>(mMinDurationiNnS).count() << "[µs]" << std::endl
                  << "    MaxDurationiNnS = " << std::chrono::duration_cast<std::chrono::microseconds>(mMaxDurationiNnS).count() << "[µs]" << std::endl
                  << "    MoyDurationiNnS = " << std::chrono::duration_cast<std::chrono::microseconds>(mMoyDurationiNnS).count() << "[µs]" << std::endl
                  << "    AccumulDurationiNnS = " << std::chrono::duration_cast<std::chrono::microseconds>(mAccumulDurationiNnS).count() << "[µs]" << std::endl
                  << "    Number of execution " << mNumberOfExecution << std::endl;
    }
    mNumberOfExecution++;
}



void PerformanceMonitor::startFunctionTimer()
{
    FunctionBegin = std::chrono::steady_clock::now();
}

void PerformanceMonitor::stopFunctionTimer()
{
    NewDuration = FunctionBegin - std::chrono::steady_clock::now();
    mAccumulFuncDurationiNnS += NewDuration;
    mMoyDurationFunctioniNnS = mAccumulFuncDurationiNnS/mNumberOfFunctionExecution;
}


//  TODO: EnableLocalPerformance.
// startPerfTimers
// stopPerTimer