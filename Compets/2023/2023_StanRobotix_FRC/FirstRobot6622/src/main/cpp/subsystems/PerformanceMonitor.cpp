#include "subsystems/PerformanceMonitor.h"

#include <iostream>

PerformanceMonitor::PerformanceMonitor()
{
}

void PerformanceMonitor::Execute()
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    doExecute();

    if (mPerformanceLogEnabled && (mSubSystemPerfStruct.mNumberOfExecution % mLogPeriodicity) == 0)
    {
        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

        // Calcul des statistiques
        std::chrono::nanoseconds wNewDuration = end - begin;
        mSubSystemPerfStruct.mAccumulDurationiNnS += wNewDuration;
        if (wNewDuration < mSubSystemPerfStruct.mMinDurationiNnS)
        {
            mSubSystemPerfStruct.mMinDurationiNnS = wNewDuration;
        }
        else if (wNewDuration > mSubSystemPerfStruct.mMaxDurationiNnS)
        {
            mSubSystemPerfStruct.mMaxDurationiNnS = wNewDuration;
        }
        mSubSystemPerfStruct.mMoyDurationiNnS = mSubSystemPerfStruct.mAccumulDurationiNnS / mSubSystemPerfStruct.mNumberOfExecution;

        //    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "[ns]" << std::endl;
        std::cout << "Statistique de performance sur le module " << getName() << std::endl
                  << "    Dernière      = " << std::chrono::duration_cast<std::chrono::microseconds>(wNewDuration).count() << "[ns]" << std::endl
                  << "    Minimum en ns = " << std::chrono::duration_cast<std::chrono::microseconds>(mSubSystemPerfStruct.mMinDurationiNnS).count() << "[ns]" << std::endl
                  << "    Maximum en ns = " << std::chrono::duration_cast<std::chrono::microseconds>(mSubSystemPerfStruct.mMaxDurationiNnS).count() << "[ns]" << std::endl
                  << "    Moyen en ns   = " << std::chrono::duration_cast<std::chrono::microseconds>(mSubSystemPerfStruct.mMoyDurationiNnS).count() << "[ns]" << std::endl
                  << "    # executions  = " << mSubSystemPerfStruct.mNumberOfExecution << std::endl;
    }
    mSubSystemPerfStruct.mNumberOfExecution++;
}

void PerformanceMonitor::resetFunctionStat()
{
   mFunctionPerfStruct.mMinDurationiNnS = std::chrono::nanoseconds::max();
   mFunctionPerfStruct.mMaxDurationiNnS = std::chrono::nanoseconds::min();
   mFunctionPerfStruct.mMoyDurationiNnS = std::chrono::nanoseconds::zero();
   mFunctionPerfStruct.mAccumulDurationiNnS = std::chrono::nanoseconds::zero();

   mFunctionPerfStruct.mNumberOfExecution = 1;
}

void PerformanceMonitor::startFunctionTimer()
{
    mStartFunctionTime = std::chrono::steady_clock::now();
}

void PerformanceMonitor::stopFunctionTimer(const std::string iFunctionName)
{
    std::chrono::nanoseconds wNewDuration = mStartFunctionTime - std::chrono::steady_clock::now();
    mFunctionPerfStruct.mAccumulDurationiNnS += wNewDuration;
    mFunctionPerfStruct.mMoyDurationiNnS = mFunctionPerfStruct.mAccumulDurationiNnS / mFunctionPerfStruct.mNumberOfExecution;
    if (wNewDuration < mFunctionPerfStruct.mMinDurationiNnS)
    {
        mFunctionPerfStruct.mMinDurationiNnS = wNewDuration;
    }
    else if (wNewDuration > mFunctionPerfStruct.mMaxDurationiNnS)
    {
        mFunctionPerfStruct.mMaxDurationiNnS = wNewDuration;
    }
    mFunctionPerfStruct.mNumberOfExecution++;

    if (timeToDisplaySystemLog())
    {
        std::cout << "Statistique de performance sur la fonction " << iFunctionName << std::endl
                  << "    Dernière      = " << std::chrono::duration_cast<std::chrono::microseconds>(wNewDuration).count() << "[ns]" << std::endl
                  << "    Minimum en ns = " << std::chrono::duration_cast<std::chrono::microseconds>(mFunctionPerfStruct.mMinDurationiNnS).count() << "[ns]" << std::endl
                  << "    Maximum en ns = " << std::chrono::duration_cast<std::chrono::microseconds>(mFunctionPerfStruct.mMaxDurationiNnS).count() << "[ns]" << std::endl
                  << "    Moyen en ns   = " << std::chrono::duration_cast<std::chrono::microseconds>(mFunctionPerfStruct.mMoyDurationiNnS).count() << "[ns]" << std::endl
                  << "    # executions  = " << mFunctionPerfStruct.mNumberOfExecution << std::endl;
    }
}

    