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
  delete motor_L;
  delete motor_R;
}

TaMatisse::TaMatisse () {
  motor_L = new CheapStepper(8,9,10,11);
  motor_R = new CheapStepper(3,4,5,6);
}

void TaMatisse::graduusMoole (int mm) {
    int steps = calculateSteps(mm);
    for (int s=0; s<steps; s++){
       motor_L->step(MOVE_COUNTERCLOCKWISE);
       motor_R->step(MOVE_CLOCKWISE);
     }
     delay(WAIT_AFTER_PRIMITIVE);
}

void TaMatisse::linksKurveMoole (int degree) {
    int steps = calculateSteps(WHEEL_DISTANCE * PI * 2 / (360 / degree));
    for (int s=0; s<steps; s++){
       motor_R->step(MOVE_CLOCKWISE);
     }
     delay(WAIT_AFTER_PRIMITIVE);
}

void TaMatisse::rechtsKurveMoole (int degree) {
  int steps = calculateSteps(WHEEL_DISTANCE * PI * 2 / (360 / degree));
  for (int s=0; s<steps; s++){
     motor_L->step(MOVE_COUNTERCLOCKWISE);
   }
   delay(WAIT_AFTER_PRIMITIVE);
}

void TaMatisse::ufEmPunktNachLinksDreie (int degree) {
  int steps = calculateSteps((WHEEL_DISTANCE / 2) * PI * 2 / (360 / degree));
  for (int s=0; s<steps; s++){
     motor_L->step(MOVE_CLOCKWISE);
     motor_R->step(MOVE_COUNTERCLOCKWISE);
  }
  delay(WAIT_AFTER_PRIMITIVE);
}

void TaMatisse::ufEmPunktNachRechtsDreie (int degree) {
  int steps = calculateSteps((WHEEL_DISTANCE / 2) * PI * 2 / (360 / degree));
  for (int s=0; s<steps; s++){
     motor_L->step(MOVE_COUNTERCLOCKWISE);
     motor_R->step(MOVE_CLOCKWISE);
  }
  delay(WAIT_AFTER_PRIMITIVE);
}

/////////////
// PRIVATE //
/////////////

int TaMatisse::calculateSteps (int mm) {
  int steps = mm / ((DIAMETER * PI )/ STEPS_PER_ROUND);
  return steps;
}
