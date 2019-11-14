/*  TaMatisse.cpp -
  v0.2 es 20191113 Rewrote movement function to use AccelStepper
	v0.1 tg 20171106 rudimentary setup with the first 3 primitives

  Simple library to draw some primitives with TaMatisse, the little bot
  for the Zukunftstag 2017 at Tamedia. It relieas on the CheapStepper
  Library https://www.airspayce.com/mikem/arduino/AccelStepper/ by Mike McCauley
*/

#include <Arduino.h>
#include "TaMatisse.h"

TaMatisse::~TaMatisse()
{
  delete motor_L;
  delete motor_R;
}

TaMatisse::TaMatisse()
{
  int motorRPin1 = 8;  // IN1 on the ULN2003 driver
  int motorRPin2 = 9;  // IN2 on the ULN2003 driver
  int motorRPin3 = 10; // IN3 on the ULN2003 driver
  int motorRPin4 = 11; // IN4 on the ULN2003 driver

  int motorLPin1 = 3; // IN1 on the ULN2003 driver
  int motorLPin2 = 4; // IN2 on the ULN2003 driver
  int motorLPin3 = 5; // IN3 on the ULN2003 driver
  int motorLPin4 = 6; // IN4 on the ULN2003 driver

  int motorType = 8; // Define the AccelStepper interface type; 4 wire motor in half step mode
  int acceleration_R = 200;
  int acceleration_L = 200;

  speed_R = 400;
  speed_L = 400;

  // Initialize with pin sequence PIN1-PIN3-PIN2-PIN4 for using the AccelStepper library with 28BYJ-48 stepper motor:
  motor_R = new AccelStepper(motorType, motorRPin1, motorRPin3, motorRPin2, motorRPin4);
  motor_L = new AccelStepper(motorType, motorLPin1, motorLPin3, motorLPin2, motorLPin4);

  // Set the maximum steps per second:
  motor_R->setMaxSpeed(1000);
  motor_L->setMaxSpeed(1000);

  // Set the maximum acceleration in steps per second^2:
  motor_R->setAcceleration(acceleration_R);
  motor_L->setAcceleration(acceleration_L);
}

void TaMatisse::graduusMoole(float mm)
{
  motor_L->setCurrentPosition(0);
  motor_R->setCurrentPosition(0);

  int steps = calculateSteps(mm);

  motor_L->moveTo(steps);
  motor_R->moveTo(steps * -1);

  while (motor_L->distanceToGo() != 0 && motor_R->distanceToGo() != 0)
  {
    motor_L->run();
    motor_R->run();
  }

  delay(WAIT_AFTER_PRIMITIVE);
}

void TaMatisse::rechtsKurveMoole(float degree)
{
  motor_R->setCurrentPosition(0);
  motor_L->setCurrentPosition(0);

  int steps = calculateSteps(WHEEL_DISTANCE * PI * 2 / (360.0 / degree));

  motor_L->moveTo(steps);

  while (motor_L->distanceToGo() != 0)
  {
    motor_L->run();
  }

  delay(WAIT_AFTER_PRIMITIVE);
}

void TaMatisse::linksKurveMoole(float degree)
{
  motor_R->setCurrentPosition(0);
  motor_L->setCurrentPosition(0);

  //int steps = calculateSteps(((WHEEL_DISTANCE / 2) * PI * 2) * (degree / 360.0));
  int steps = calculateSteps(WHEEL_DISTANCE * PI * 2 / (360.0 / degree));

  motor_R->moveTo(steps * -1);

  while (motor_R->distanceToGo() != 0)
  {
    motor_R->run();
  }

  delay(WAIT_AFTER_PRIMITIVE);
}

void TaMatisse::ufEmPunktNachRechtsDreie(float degree)
{
  motor_L->setCurrentPosition(0);
  motor_R->setCurrentPosition(0);

  int steps = calculateSteps(((WHEEL_DISTANCE / 2) * PI * 2) * (degree / 360.0));
  //steps = 860;
  motor_R->moveTo(steps);
  motor_L->moveTo(steps);

  while (motor_L->distanceToGo() != 0 && motor_R->distanceToGo() != 0)
  {
    motor_L->run();
    motor_R->run();
  }

  delay(WAIT_AFTER_PRIMITIVE);
}

void TaMatisse::ufEmPunktNachLinksDreie(float degree)
{
  motor_L->setCurrentPosition(0);
  motor_R->setCurrentPosition(0);

  int steps = calculateSteps(((WHEEL_DISTANCE / 2) * PI * 2) * (degree / 360.0));

  motor_R->moveTo(steps * -1);
  motor_L->moveTo(steps * -1);

  while (motor_L->distanceToGo() != 0 && motor_R->distanceToGo() != 0)
  {
    motor_L->run();
    motor_R->run();
  }

  delay(WAIT_AFTER_PRIMITIVE);
}

void TaMatisse::bogeNachRechtsMoole(float degree, float radius)
{
  int stepsLeft = calculateSteps((degree / 360) * (2 * PI * (radius + (WHEEL_DISTANCE / 2))));
  int stepsRight = calculateSteps((degree / 360) * (2 * PI * (max(0, radius - (WHEEL_DISTANCE / 2)))));

  float stepsDifference = abs(stepsLeft - stepsRight);
  float stepsRatio = stepsDifference / stepsLeft;
  float accelRight = speed_R * (1 - stepsRatio);

  motor_L->setCurrentPosition(0);
  motor_R->setCurrentPosition(0);

  // We have to switch from acceleration mode to constant speed setCurrentPosition has the side effect of setting speed to 0
  motor_R->setSpeed(accelRight * -1);
  motor_L->setSpeed(speed_L);

  while (motor_L->currentPosition() != stepsLeft)
  {
    motor_L->runSpeed();

    if (motor_R->currentPosition() != stepsRight)
    {
      motor_R->runSpeed();
    }
  }
  delay(WAIT_AFTER_PRIMITIVE);
}

void TaMatisse::bogeNachLinksMoole(float degree, float radius)
{
  int stepsLeft = calculateSteps((degree / 360) * (2 * PI * (max(0, radius - (WHEEL_DISTANCE / 2)))));
  int stepsRight = calculateSteps((degree / 360) * (2 * PI * (radius + (WHEEL_DISTANCE / 2))));

  float stepsDifference = abs(stepsLeft - stepsRight);
  float stepsRatio = stepsDifference / stepsRight;
  float accelLeft = speed_L * (1 - stepsRatio);

  motor_L->setCurrentPosition(0);
  motor_R->setCurrentPosition(0);

  // We have to switch from acceleration mode to constant speed setCurrentPosition has the side effect of setting speed to 0
  motor_R->setSpeed(speed_R * -1);
  motor_L->setSpeed(accelLeft);

  while (motor_R->currentPosition() != stepsRight * -1)
  {
    motor_R->runSpeed();

    if (motor_L->currentPosition() != accelLeft)
    {
      motor_L->runSpeed();
    }
  }
  delay(WAIT_AFTER_PRIMITIVE);
}

void TaMatisse::warte(int seconds)
{
  for (int i = 0; i < seconds; i++)
    delay(1000);
}

void TaMatisse::fertig(void)
{
  for (;;)
    delay(3600UL * 1000);
}

float TaMatisse::radAbstand(void)
{
  return WHEEL_DISTANCE;
}

/////////////
// PRIVATE //
/////////////

int TaMatisse::calculateSteps(float mm)
{
  int steps = roundf(mm / ((DIAMETER * PI) / STEPS_PER_ROUND));
  return steps;
}