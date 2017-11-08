#include <Arduino.h>
#include "TaMatisse.h"
#include <math.h>

// Simple example for driving the TaMatisse, our little painting bot around
TaMatisse werdBot;

long f(long n = 0);
double squareGrowth(double n = 1);

void setup() {
}

void loop() {
  //paint8();
  //f();
  squareGrowth(10);
}

long f(long n = 0) {
  long radius = n;
  int angle = 90;
  werdBot.bogeNachLinksMoole(angle, radius);
  return f(n+n+1);
}

double squareGrowth(double n = 1) {
  for(int i = 0; i < 4; i++) {
    werdBot.graduusMoole(n);
    werdBot.ufEmPunktNachLinksDreie(90);
  }
  werdBot.ufEmPunktNachLinksDreie(45);

  return squareGrowth(sqrt(2*(n*n)));
}

void box() {
  werdBot.graduusMoole(40);
  werdBot.ufEmPunktNachLinksDreie(90);
}

void paint8() {
  // draw an 8 on the floor. Run for cover. :)
  for (int i=0; i<4; i++) {
    // turn left
    werdBot.linksKurveMoole(90);
    // go straight, paint 50mm line
    werdBot.graduusMoole(50);
  }
  for (int i=0; i<4; i++) {
    // turn right
    werdBot.rechtsKurveMoole(90);
    // go straight, paint 50mm line
    werdBot.graduusMoole(50);
  }
}
