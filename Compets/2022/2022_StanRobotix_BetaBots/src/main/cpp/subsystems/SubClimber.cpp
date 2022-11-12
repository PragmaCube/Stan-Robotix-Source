// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/SubClimber.h"





SubClimber::SubClimber() 
{
  // Implementation of subsystem constructor goes here.
}

void SubClimber::Periodic() 
{
  // Implementation of subsystem periodic method goes here.

}

void SubClimber::SimulationPeriodic() 
{
    
  // Implementation of subsystem simulation periodic method goes here.
}

void SubClimber::Stop()
{
    mMotorClimber.Set(0);
};


void SubClimber::Stage(Height iHeight)
{
    switch(iHeight)
    {
        case h1:
        if (kHeightS1-1 < SubClimber::GetEncoderPosition() < kHeightS1+1)
        {
            mMotorClimber.Set(kSpeedUp);   
        }
        else if ( kHeightS1+1 > SubClimber::GetEncoderPosition() > kHeightS1-1)
        {
            mMotorClimber.Set(-kSpeedUp);
        }
        break;
        
        case h2:
        if (kHeightS2-1 < SubClimber::GetEncoderPosition() < kHeightS2 +1)
        {
            mMotorClimber.Set(kSpeedUp);   
        }
        else if (kHeightS2+1 > SubClimber::GetEncoderPosition() > kHeightS2-1 )
        {
            mMotorClimber.Set(-kSpeedUp);
        }
        break;
        
        case h3:
       
        if ( kHeightS3 -1 < SubClimber::GetEncoderPosition() < kHeightS3 + 1)
        {
            mMotorClimber.Set(kSpeedUp);   
        }
        else if ( kHeightS3 +1 > SubClimber::GetEncoderPosition() > kHeightS3-1)
        {
            mMotorClimber.Set(-kSpeedUp);
        }
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