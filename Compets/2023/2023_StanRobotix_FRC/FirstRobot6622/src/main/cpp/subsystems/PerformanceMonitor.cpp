#include "subsystems/PerformanceMonitor.h"

#include <iostream>

PerformanceMonitor::PerformanceMonitor()
{
}

void PerformanceMonitor::Execute()
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    doExecute();

    if (mPerformanceLogEnabled )
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
        if (timeToDisplaySystemLog())
        {
        std::cout << "    Statistics for          "   << getName()                                                                                                          << std::endl
                  << "    NewDuration         =   "   << std::chrono::duration_cast<std::chrono::microseconds>(wNewDuration).count()                              << "[µs]" << std::endl
                  << "    MinDurationiNnS     =   "   << std::chrono::duration_cast<std::chrono::microseconds>(mSubSystemPerfStruct.mMinDurationiNnS).count()     << "[µs]" << std::endl
                  << "    MaxDurationiNnS     =   "   << std::chrono::duration_cast<std::chrono::microseconds>(mSubSystemPerfStruct.mMaxDurationiNnS).count()     << "[µs]" << std::endl
                  << "    MoyDurationiNnS     =   "   << std::chrono::duration_cast<std::chrono::microseconds>(mSubSystemPerfStruct.mMoyDurationiNnS).count()     << "[µs]" << std::endl
                  << "    AccumulDurationiNnS =   "   << std::chrono::duration_cast<std::chrono::microseconds>(mSubSystemPerfStruct.mAccumulDurationiNnS).count() << "[µs]" << std::endl
                  << "    Number of execution =   "   << mSubSystemPerfStruct.mNumberOfExecution << std::endl;
    }
    }
    mSubSystemPerfStruct.mNumberOfExecution++;
}

void PerformanceMonitor::startFunctionTimer()
{
    FunctionBegin = std::chrono::steady_clock::now();
}

void PerformanceMonitor::stopFunctionTimer(const std::string iComment)
{
    std::chrono::nanoseconds wNewDuration = FunctionBegin - std::chrono::steady_clock::now();
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

    if (timeToDisplaySystemLog())
    {
        std::cout << "Temp execution de la fonction " << iComment << std::endl;
        std::cout <<"La duree est de "          << wNewDuration << " nanosecond" << std::endl;
        std::cout <<"La moyenne est de "        << mFunctionPerfStruct.mMoyDurationiNnS<< " nanosecond" << std::endl;
        std::cout <<"La valeur maximal est de " << mFunctionPerfStruct.mMaxDurationiNnS<< " nanosecond" << std::endl;
        std::cout <<"La valeur minimal est de " << mFunctionPerfStruct.mMinDurationiNnS<< " nanosecond" << std::endl;
    }
    mFunctionPerfStruct.mNumberOfExecution++;
}