/*  TaMatisse.cpp -
	v0.1 tg 20171106 rudimentary setup with the first 3 primitives

  Simple library to draw some primitives with TaMatisse, the little bot
  for the Zukunftstag 2017 at Tamedia. It relieas on the CheapStepper
  Library https://github.com/tyhenry/CheapStepper by Tyler Henry

  The upstream CheapStepper was a bit too cheap, the cosntructor would
  not work for two motors, therefor we had to fix it to work for TaMatisse.

*/


#include <Arduino.h>
#include "TaMatisse.h"

TaMatisse::~TaMatisse () {
  delete motor_L;
  delete motor_R;
}

TaMatisse::TaMatisse () {
  motor_L = new CheapStepper(8,9,10,11);
  motor_R = new CheapStepper(3,4,5,6);
}

void TaMatisse::graduusMoole (float mm) {
    int steps = calculateSteps(mm);

    for (int s=0; s<steps; s++){
      if(mm>=0) {
        motor_L->step(MOVE_COUNTERCLOCKWISE);
        motor_R->step(MOVE_CLOCKWISE);
      }
      else {
        motor_L->step(MOVE_CLOCKWISE);
        motor_R->step(MOVE_COUNTERCLOCKWISE);
      }
     }
     delay(WAIT_AFTER_PRIMITIVE);
}

void TaMatisse::linksKurveMoole (float degree) {
    int steps = calculateSteps(WHEEL_DISTANCE * PI * 2 / (360.0 / degree));
    for (int s=0; s<steps; s++){
       motor_R->step(MOVE_CLOCKWISE);
     }
     delay(WAIT_AFTER_PRIMITIVE);
}

void TaMatisse::rechtsKurveMoole (float degree) {
  int steps = calculateSteps(WHEEL_DISTANCE * PI * 2 / (360.0 / degree));
  for (int s=0; s<steps; s++){
     motor_L->step(MOVE_COUNTERCLOCKWISE);
   }
   delay(WAIT_AFTER_PRIMITIVE);
}

void TaMatisse::ufEmPunktNachLinksDreie (float degree) {
  int steps = calculateSteps((WHEEL_DISTANCE / 2) * PI * 2 / (360.0 / degree));
  for (int s=0; s<steps; s++){
     motor_L->step(MOVE_CLOCKWISE);
     motor_R->step(MOVE_CLOCKWISE);
  }
  delay(WAIT_AFTER_PRIMITIVE);
}

void TaMatisse::ufEmPunktNachRechtsDreie (float degree) {
  int steps = calculateSteps((WHEEL_DISTANCE / 2) * PI * 2 / (360.0 / degree));
  for (int s=0; s<steps; s++){
     motor_L->step(MOVE_COUNTERCLOCKWISE);
     motor_R->step(MOVE_COUNTERCLOCKWISE);
  }
  delay(WAIT_AFTER_PRIMITIVE);
}


void TaMatisse::bogeNachLinksMoole(float degree, float radius) {
  int stepsLeft = calculateSteps(PI * 2 * (radius -  WHEEL_DISTANCE / 2) * degree / 360.0);
  int stepsRight = calculateSteps(PI * 2 * (radius + WHEEL_DISTANCE / 2) * degree / 360.0);
  float incLeft = (float)stepsLeft / stepsRight;
  float leftStepped = 0;

  for (int right=0, left=0; right < stepsRight; right++) {
    motor_R->step(MOVE_CLOCKWISE);
    leftStepped += incLeft;
    if (abs(roundf(leftStepped)) > left) {
      if (stepsLeft < 0)
        motor_L->step(MOVE_CLOCKWISE);
      else
        motor_L->step(MOVE_COUNTERCLOCKWISE);
      left++;
    }
  }
  delay(WAIT_AFTER_PRIMITIVE);
}

void TaMatisse::bogeNachRechtsMoole (float degree, float radius) {
  int stepsRight = calculateSteps(PI * 2 * (radius -  WHEEL_DISTANCE / 2) * degree / 360.0);
  int stepsLeft = calculateSteps(PI * 2 * (radius +  WHEEL_DISTANCE / 2) * degree / 360.0);
  float incRight = (float)stepsRight / stepsLeft;
  float rightStepped = 0;

  for (int left=0, right=0; left < stepsLeft; left++) {
    motor_L->step(MOVE_COUNTERCLOCKWISE);
    rightStepped += incRight;
    if (abs(roundf(rightStepped)) > right) {
      if (stepsRight < 0)
        motor_R->step(MOVE_COUNTERCLOCKWISE);
      else
        motor_R->step(MOVE_CLOCKWISE);
      right++;
    }
  }
  delay(WAIT_AFTER_PRIMITIVE);
}

void TaMatisse::warte(int seconds) {
  for (int i = 0; i < seconds; i++)
    delay(1000);
}

void TaMatisse::fertig (void) {
  for (;;)
    delay(3600UL * 1000);
}

float TaMatisse::radAbstand(void) {
  return WHEEL_DISTANCE;
}

/////////////
// PRIVATE //
/////////////

int TaMatisse::calculateSteps (float mm) {
  int steps = abs(roundf(mm / ((DIAMETER * PI) / STEPS_PER_ROUND)));
  return steps;
}
