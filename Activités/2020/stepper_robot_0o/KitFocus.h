#include <AccelStepper.h>
//la librairie IRremote crée une variable globale, nous ne voulons pas l'avoir dans la librairie
//donc, nous forcons l'inclusion de IRremoteInt.h si KitFocus.h est utilisé pour générer la librairie KitFocus
#ifdef KIT_FOCUS_LIB
  #include <IRremoteInt.h>
#else
  #include <IRremote.h>
#endif


//déclaration de la classe RobotKitFocus
//elle contient deux moteurs pas à pas et un récépteur infrarouge
class RobotKitFocus
{
  private:
    AccelStepper  stepper1, stepper2; //déclaration des deux moteurs pas à pas
    IRrecv *      pIrReceiver;        //déclaration du pointeur de l'objet IrReceiver créé par la librarie IrRemote (purement formel)
    
    int           forwardCode, backwardCode, rightCode, leftCode; //codes IR des différentes directions du robot
    int           stepperSpeed;                                   //vitesse du robot
    bool          bState = LOW;                                   //état du robot HIGH = en mouvement, LOW = arrêté
    long          lLastPressTime = 0;                             //délai depuis la récéption du dernier message IR
    const int     cMaxTime = 150;                                 //délai maximum entre la récéption des messages pour que le robot continue à avancer
    const int     cFullStep = 4;                                  //nombre de pas par tour pour les moteurs pas à pas 4: pas complets 8:demis-pas

  public:
    RobotKitFocus (int irReceivePin = 2, int motorPin1 = 4, int motorPin2 = 5, int motorPin3 = 6, int motorPin4 = 7, 
                                         int motorPin5 = 8, int motorPin7 = 9, int motorPin6 = 10, int motorPin8 = 11): 
                  stepper1(cFullStep, motorPin1, motorPin3, motorPin2, motorPin4), 
                  stepper2(cFullStep, motorPin5, motorPin7, motorPin6, motorPin8),
                  pIrReceiver (&IrReceiver) 
                  {
                      pIrReceiver->begin(irReceivePin); // démarer le récepteur infrarouge
                  }
    void updateRobot ();      //doit être appelé constamment pour que le robot applique les messages IR reçus et que les moteurs tournent
    void setStepperSpeed (int pSpeed);
    void setStepperMaxSpeed (int pMaxSpeed);
    void setStepperAcceleration (int pAcceleration);
    void defineControls (int pForwardCode, int pBackwardCode, int pRightCode, int pLeftCode);   //défini les codes IR pour les contrôles
    void setStepperPinsInverted (); //à appeler si le robot marche à l'envers
};
