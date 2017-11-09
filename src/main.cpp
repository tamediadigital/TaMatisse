#include <Arduino.h>
#include "TaMatisse.h"
#include <math.h>

// Simple example for driving the TaMatisse, our little painting bot around
TaMatisse werdBot;

long f(long n);
double squareGrowth(double n);

void setup() {
}

/*
 * running for cover following the path of the golden spiral
 */
long f(long f1 = 0, long f2 = 1) {
  int angle = 90;
  //std::cout << "f1:" << f1 << "/f2:" << f2 << " --- ";
  werdBot.bogeNachLinksMoole(angle, f1);
  return f(f2, f1 >= 1 ? f1 + f2 : 1);
}

/*
 * Attention -> experimental(!)
 */
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

void schnaegg(void) {
  for (int i = 1; i < 10; i++) {
    werdBot.bogeNachLinksMoole(180.0, 20.0*i);
  }
}

void t(void) {
  werdBot.warte(4);

  werdBot.graduusMoole(130);
  werdBot.ufEmPunktNachLinksDreie(90);
  werdBot.graduusMoole(40);
  werdBot.bogeNachRechtsMoole(90, 10);
  werdBot.graduusMoole(20);
  werdBot.bogeNachRechtsMoole(48, 10);
  werdBot.graduusMoole(156);
  werdBot.bogeNachRechtsMoole(42, 10);
  werdBot.graduusMoole(10);
  werdBot.bogeNachRechtsMoole(90, 10);
  werdBot.graduusMoole(70);
  werdBot.ufEmPunktNachLinksDreie(90);
  werdBot.graduusMoole(76);
  werdBot.bogeNachRechtsMoole(90, 10);
  werdBot.graduusMoole(50);
  werdBot.bogeNachRechtsMoole(90, 10);
  werdBot.graduusMoole(76);
  werdBot.ufEmPunktNachLinksDreie(90);
  werdBot.graduusMoole(80);
  werdBot.bogeNachLinksMoole(90, 30);
  werdBot.bogeNachLinksMoole(27, 106);
  werdBot.bogeNachRechtsMoole(117, 10);
  werdBot.graduusMoole(60);
  werdBot.bogeNachRechtsMoole(59, 10);
  werdBot.bogeNachRechtsMoole(61, 136);
  werdBot.bogeNachRechtsMoole(60, 70);

  werdBot.fertig();
}

void calibrate(void) {
  werdBot.graduusMoole(100);
  for (int i = 0; i < 10; i++)
    werdBot.ufEmPunktNachLinksDreie(360);
  werdBot.graduusMoole(200);
  for (int i = 0; i < 10; i++)
    werdBot.ufEmPunktNachRechtsDreie(360);
  werdBot.graduusMoole(100);
}


void loop() {
  paint8();
  //f();
  //squareGrowth(10);
  //t();
  //schnaegg();
}
