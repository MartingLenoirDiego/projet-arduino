
#include <Stepper.h>
const float STEPS_PER_REV = 32; 
const float GEAR_RED = 64;
const float STEPS_PER_OUT_REV = STEPS_PER_REV * GEAR_RED;
int StepsRequired;
String InBytes;
Stepper steppermotor(STEPS_PER_REV, 8, 10, 9, 11);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  char commande;  
  if (Serial.available()>0) {
     InBytes = Serial.readStringUntil('\n');
     if (InBytes=="open"){
        StepsRequired  =  - STEPS_PER_OUT_REV / 4;   
        steppermotor.setSpeed(700);  
        steppermotor.step(StepsRequired);
      }else if (InBytes=="close") {
        StepsRequired  =   STEPS_PER_OUT_REV / 4;   
        steppermotor.setSpeed(700);  
        steppermotor.step(StepsRequired);
      }
  }
}
  
  
