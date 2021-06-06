#define KIT_FOCUS_LIB
#include "KitFocus.h"

void RobotKitFocus::updateRobot ()
{
  int receivedCode;
  
  if (pIrReceiver->decode()) 
  {
    receivedCode = pIrReceiver->decodedIRData.command;
    Serial.print("Code recu : ");
    Serial.println(IrReceiver.decodedIRData.command);
    if (receivedCode == forwardCode)
    {
      if (bState == LOW)
      { 
        bState = HIGH;  // Button pressed, so set bState to HIGH
        stepper1.setSpeed(-stepperSpeed);
        stepper2.setSpeed(-stepperSpeed);
        stepper1.enableOutputs();
        stepper2.enableOutputs();
      }
      lLastPressTime = millis();
    }
    else if (receivedCode == backwardCode)
    {
      if (bState == LOW)
      { 
        bState = HIGH;  // Button pressed, so set bState to HIGH
        stepper1.setSpeed(stepperSpeed);
        stepper2.setSpeed(stepperSpeed);
        stepper1.enableOutputs();
        stepper2.enableOutputs();
      }
      lLastPressTime = millis();
    }
    else if (receivedCode == rightCode)
    {
      if (bState == LOW)
      { 
        bState = HIGH;  // Button pressed, so set bState to HIGH
        stepper1.setSpeed(-stepperSpeed);
        stepper2.setSpeed(stepperSpeed);
        stepper1.enableOutputs();
        stepper2.enableOutputs();
      }
      lLastPressTime = millis();
    }
   else if (receivedCode == leftCode)
   {
      if (bState == LOW)
      { 
        bState = HIGH;  // Button pressed, so set bState to HIGH
        stepper1.setSpeed(stepperSpeed);
        stepper2.setSpeed(-stepperSpeed);
        stepper1.enableOutputs();
        stepper2.enableOutputs();
      }
      lLastPressTime = millis();
    }
    pIrReceiver->resume(); // Receive the next value
  }
  if (bState == HIGH && millis() - lLastPressTime > cMaxTime)
  {
    bState = LOW; // Haven't heard from the button for a while, so not pressed
    stepper1.disableOutputs();
    stepper2.disableOutputs();
  }
  if (bState == HIGH)
  {
    stepper1.runSpeed();
    stepper2.runSpeed();
  }
}

void RobotKitFocus::setStepperSpeed (int pSpeed)
{
  stepperSpeed = pSpeed;
}

void RobotKitFocus::setStepperMaxSpeed (int pMaxSpeed)
{
  stepper1.setMaxSpeed(pMaxSpeed);
  stepper2.setMaxSpeed(pMaxSpeed); 
}

void RobotKitFocus::setStepperAcceleration (int pAcceleration)
{
  stepper1.setAcceleration(pAcceleration);
  stepper1.setAcceleration(pAcceleration);
}

void RobotKitFocus::defineControls (int pForwardCode, int pBackwardCode, int pRightCode, int pLeftCode)
{
  forwardCode  = pForwardCode;
  backwardCode = pBackwardCode;
  rightCode    = pRightCode;
  leftCode     = pLeftCode;
}

void RobotKitFocus::setStepperPinsInverted ()
{
  stepper1.setPinsInverted();
  stepper2.setPinsInverted();
}
