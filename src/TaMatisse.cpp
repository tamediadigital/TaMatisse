/*  TaMatisse.cpp -
	v0.1 tg 20171106 rudimentary setup with the first 3 primitives

  Simple library to draw some primitives with TaMatisse, the little bot
  for the Zukunftstag 2017 at Tamedia. It relieas on the CheapStepper
  Library https://github.com/tyhenry/CheapStepper by Tyler Henry

  The upstream CheapStepper was a bit too cheap, the cosntructor would
  not work for two motors, therefor we had to fix it to work for TaMatisse.
  
*/


#include "Arduino.h"
#include "TaMatisse.h"

TaMatisse::~TaMatisse () {
  delete stepper_L;
  delete stepper_R;
}

TaMatisse::TaMatisse () {
  stepper_L = new CheapStepper(8,9,10,11);
  stepper_R = new CheapStepper(3,4,5,6);
}

void TaMatisse::graduusMoole (int mm) {
    int steps = mm / ((DIAMETER * PI )/ STEPS_PER_ROUND);
    for (int s=0; s<steps; s++){
       stepper_L->step(MOVE_CLOCKWISE);
       stepper_R->step(MOVE_COUNTERCLOCKWISE);
     }
     delay(WAIT_AFTER_PRIMITIVE);
}

void TaMatisse::linksKurveMoole (int degree) {
    int mm = WHEEL_DISTANCE * PI * 2 / (360 / degree);
    int steps = mm / ((DIAMETER * PI )/ STEPS_PER_ROUND);
    for (int s=0; s<steps; s++){
       stepper_R->step(MOVE_CLOCKWISE);
     }
     delay(WAIT_AFTER_PRIMITIVE);
}

void TaMatisse::rechtsKurveMoole (int degree) {
    int mm = WHEEL_DISTANCE * PI * 2 / (360 / degree);
    int steps = mm / ((DIAMETER * PI )/ STEPS_PER_ROUND);
    for (int s=0; s<steps; s++){
       stepper_L->step(MOVE_CLOCKWISE);
     }
     delay(WAIT_AFTER_PRIMITIVE);
}


/////////////
// PRIVATE //
/////////////
