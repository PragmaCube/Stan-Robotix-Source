// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once


#include "frc/smartdashboard/Smartdashboard.h"
#include "networktables/NetworkTable.h"
#include "networktables/NetworkTableInstance.h"
#include "networktables/NetworkTableEntry.h"
#include "networktables/NetworkTableValue.h"

#include "Constants.h"
#include "PerformanceMonitor.h"

class SubLimelight : public PerformanceMonitor
{

public:
  SubLimelight();

  void Init();

  void Enable(const bool iEnable);

  void EnableSubsystemLog(bool iEnable) { mSubsystemLogEnabled = iEnable; }

  void doExecute();

  double getTargetOffsetAngleHorizontal() { return mTargetOffsetAngle_Horizontal; }
  double getTargetOffsetAngleVertical() { return mTargetOffsetAngle_Vertical; }
  double getTargetArea() { return mTargetArea; }
  double getTargetSkew() { return mTargetSkew; }

  enum ePos { eX, eY, eZ, eRoll, ePitch, eYaw };  //Enum pour choisir ce qu'on veut dans la methode get
  enum eReferential { eField, eTag };            //Enum pour choisir referientiel

  double getPos(ePos iPos, eReferential iReferential);
  private:
  bool mIsEnabled = false;
  bool mSubsystemLogEnabled = false;

  double mTargetOffsetAngle_Horizontal = 0.0;
  double mTargetOffsetAngle_Vertical = 0.0;
  double mTargetArea = 0.0;
  double mTargetSkew = 0.0;

  std::shared_ptr<nt::NetworkTable> mNetworkTable;

  virtual std::string getName() { return "SubLimelight"; } // TODO variable globale publique
  
  std::vector<double> mFieldBotPos = { 0, 0, 0 , 0, 0, 0, };
  std::vector<double> mTagBotPos   = { 0, 0, 0 , 0, 0, 0, };
  
  
  };
