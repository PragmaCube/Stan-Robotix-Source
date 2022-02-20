#include "pid.h"

namespace rbtxpid
{
    pidController::pidController(float iSetPoint, float iKproportional, float iKintegral, float iKderivative)
    {
        // Initialisation des variables
        mSetPoint = iSetPoint;
        mKproportional = iKproportional;
        mKintegral = iKintegral;
        mKderivative = iKderivative;
        mLastTime = std::chrono::steady_clock::now();
        mIntegralError = 0;
        mLastError = 0;
    }

    // Destructeur inutile
    pidController::~pidController() { }

    // Mise à juor des variables
    void pidController::_update(float iError)
    {
        // Initialisation des variables temporelles
        std::chrono::steady_clock::time_point wCurrentTime = std::chrono::steady_clock::now();
        float wDt = std::chrono::duration_cast<std::chrono::microseconds>(wCurrentTime - mLastTime).count();
        wDt = wDt / 1000000;
        mLastTime = wCurrentTime;

        // Mise à jour de l'intégrale
        mIntegralError += iError * wDt;

        // Mise à jour de la dérivée
        mDerivativeError = (iError - mLastError) / wDt;
        mLastError = iError;
    }

    // Retourne la sortie attendue
    float pidController::getOutput(float iError)
    {
        _update(iError);
        float wProportional = mKproportional * iError;
        float wIntegral = mKintegral * mIntegralError;
        float wDerivative = mKderivative * mDerivativeError;
        return wProportional + wIntegral + wDerivative;
    }
}

