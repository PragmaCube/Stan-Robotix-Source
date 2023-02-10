/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Subsystems\Vision.h"
#include "Subsystems\DriveTrain.h"
#include "Timer.h"
#include <math.h>
#include <iostream>
#include "Robot.h"

Vision::Vision() : Subsystem("Vision"), mCameraServer(nullptr) {}

void Vision::Initialization()
{
  foundContour = true;
  if (mCameraServer != nullptr)
  {
    mCameraServer->GetInstance()->AddAxisCamera("Axis Cam",kCameraIP);
    mCameraServer->GetInstance()->PutVideo("Camera MS",axisCamWidth,axisCamHeight);
  }

  mNetworkTableInstanceInst = nt::NetworkTableInstance::GetDefault();
}

void Vision::InitDefaultCommand() {}

double Vision::GetContoursCentreX(){
  auto table = mNetworkTableInstanceInst.GetTable("GRIP/myContoursReport");

  auto wCoordX = table->GetEntry("centerX").GetDoubleArray(0);
  
  if (!wCoordX.empty())
  {
    if (wCoordX.size() == 2)
    {
      foundContour = true;
      return (wCoordX[0]+wCoordX[1])/2.0;
    }
  }
  foundContour = false;
  return -1;
}

double Vision::GetContourAngle()
{
  //angle forme entre avant du robot et hatch (entre -90 et 90)
  auto table = mNetworkTableInstanceInst.GetTable("GRIP/myContoursReport");

  auto wCoordX = table->GetEntry("centerX").GetDoubleArray(0);
  auto wArea = table->GetEntry("area").GetDoubleArray(0);
  if (!wArea.empty())
  {
    if (wArea.size() == 2)
    {
      foundContour = true;
      //distance au hatch en pieds
      double dist = Robot::m_gps.GetCapteurDistance()/12.0;
      //formule avec ln pour trouver angle
      double absoluteAngle = log(std::min(wArea[0],wArea[1])/std::max(wArea[0],wArea[1])/(0.041+0.007*dist));
      
      // en face du hatch, si bande à ma droite est plus proche :
      if(wCoordX[0]>wCoordX[1])
      {
        if (wArea[0]>wArea[1])
        {
        return -absoluteAngle;
        }
      }
      else
      {
        if (wArea[0]<wArea[1])
        {
        return -absoluteAngle;
        }
      }
      return absoluteAngle;
      //return angle orienté de (arrière-avant du robot) et (avant-arriere du hatch) en degrés
    }
  }
  foundContour = false;
  return 0;
}

bool Vision::FoundContour()
{
  return foundContour;
}