#ifndef TAMATISSE_H
#define TAMATISSE_H

#include "CheapStepper.h"

class TaMatisse {
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
<<<<<<< HEAD
  const float WHEEL_DISTANCE = 135;
=======
  const float WHEEL_DISTANCE = 137.0;
>>>>>>> 43d131e16c32ab7fdab33ceb3e1ef4193ab2f126

public:
  TaMatisse();
  ~TaMatisse();

  // paints a straight line (by default 50mm long)
  void graduusMoole(float mm = 50.0);
  // paints a left curve, by default by 90 degree
  void linksKurveMoole(float degree = 90.0);
  // paints a right curve, by default by 90 degree
  void rechtsKurveMoole(float degree = 90.0);
  // turn left on the spot
  void ufEmPunktNachLinksDreie(float degree = 90.0);
  // turn right on the spot
  void ufEmPunktNachRechtsDreie(float degree = 90.0);
  // turn left in a bow around a spot radius mm away
  void bogeNachLinksMoole(float degree = 90.0, float radius = 10.0);
  // turn right in a bow around a spot radius mm away
  void bogeNachRechtsMoole(float degree = 90.0, float radius = 10.0);
  // wait specified amount of seconds before moving on
  void warte(int seconds);
  // stop execution
  void fertig (void);
  // get the WHEEL_DISTANCE
  float radAbstand(void);

private:

  // both stepper motors
  CheapStepper *motor_L;
  CheapStepper *motor_R;

  int calculateSteps (float mm);
};

#endif
