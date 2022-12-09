// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubClimber.h"
#include <iostream>




SubClimber::SubClimber() 
{
  // Implementation of subsystem constructor goes here.
  frc::SmartDashboard::PutNumber("Offset", mOffset);
}

void SubClimber::Periodic() 
{
  // Implementation of subsystem periodic method goes here.
  //mOffset = frc::SmartDashboard::GetNumber("Offset : ",0);
  mPidController.SetReference(mHeight_, rev::ControlType::kSmartMotion);
  //std::cout<<mHeight_<<std::endl;
}

void SubClimber::SimulationPeriodic() 
{
    
  // Implementation of subsystem simulation periodic method goes here.
}

void SubClimber::Stop()
{
    mMotorClimber.Set(0);
};

void SubClimber::UpHold()
{
    if (mHeight_ > kHeightS3)
    {
        mHeight_ -= 1;
    }
    
};

void SubClimber::DownHold()
{
    if (mHeight_ < 0)
    {
        mHeight_ += 1;
    }
};


void SubClimber::Stage(Height iHeight)
{
    switch(iHeight)
    {
        case h0:
            mHeight_ = kMinHeight;
        break;

        case h1:
            mHeight_ = kHeightS1;
        break;
        
        case h2:
            mHeight_ = kHeightS2;
        break;
        
        case h3:
            mHeight_ = kHeightS3;
        break;
        
        default:
            mMotorClimber.Set(0);
        
    }

    

};
//mMotorClimber.Set(kSpeedDown);
void SubClimber::Down()
{
    int hauteur = SubClimber::GetEncoderPosition();
    while (hauteur-SubClimber::GetEncoderPosition() < threeinch)
    {
        mMotorClimber.Set(kSpeedDown);
    }
    mMotorClimber.Set(0);

};

int SubClimber::GetEncoderPosition()
{
    return -(int(mMotorEncoder.GetPosition()));
}