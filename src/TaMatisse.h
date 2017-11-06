#ifndef TAMATISSE_H
#define TAMATISSE_H

#include "CheapStepper.h"
//#include <CheapStepper.h>

class TaMatisse {

public:
  TaMatisse();
  ~TaMatisse();

  // paints a straight line (by default 50mm long)
  void graduusMoole(int mm = 50);
  // paints a left curve, by default by 90 degree
  void linksKurveMoole(int degree = 90);
  // paints a right curve, by default by 90 degree
  void rechtsKurveMoole(int degree = 90);
private:
  // setting the const for CW turning
  const boolean MOVE_CLOCKWISE = true;
  // setting the const for CCW turning
  const boolean MOVE_COUNTERCLOCKWISE = false;
  // diameter of the wheel of the bot in mm
  const float DIAMETER = 74.3;
  // steps per round of the stepper motor
  const int STEPS_PER_ROUND = 4096;
  // wait for # ms after drawing a primitive
  const int WAIT_AFTER_PRIMITIVE = 1000;
  // distance between the two wheel (for drawing curves)
  const float WHEEL_DISTANCE = 118.82;
  // both stepper motors
  CheapStepper *stepper_L;
  CheapStepper *stepper_R;
};

#endif
