/* Prototypes.cpp -

  Collection of functions to draw some more or less complex graphics.

*/
#include <Arduino.h>
#include "TaMatisse.h"
#include "Prototypes.h"

extern TaMatisse werdBot;

/* functions to draw a fibonacci spiral */

/*
 * running for cover following the path of the golden spiral
 */
long f(long f1, long f2) {
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

/* draw a box with mm size */
void box(float mm) {
  for (int i = 0; i < 4; i++) {
    werdBot.ufEmPunktNachLinksDreie(90);
    werdBot.graduusMoole(mm);
  }
  werdBot.fertig();
}

/* draw an  8 */
void achti(void) {
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
  werdBot.fertig();
}


void hertz() {
  werdBot.linksKurveMoole(180);
  werdBot.graduusMoole(118.82);
  werdBot.ufEmPunktNachLinksDreie(90);
  werdBot.graduusMoole(118.82);
  werdBot.linksKurveMoole(180);
  werdBot.fertig();
}

void drueegg() {
  for (int i=0; i<3; i++) {
    werdBot.ufEmPunktNachRechtsDreie(120);
    werdBot.graduusMoole(90);
  }
  werdBot.fertig();
}

/* print regular egge-side shapes with mm size */
void mehregg(int egge, float mm) {
  float winkel = 360.0 / egge;

  for (int i = 0; i < egge; i++) {
    werdBot.ufEmPunktNachRechtsDreie(winkel);
    werdBot.graduusMoole(mm);
  }
}

void davidStern() {
   // let the loop run twice!

  for (int i=0; i<3; i++) {
    werdBot.ufEmPunktNachRechtsDreie(120);
    werdBot.graduusMoole(90);
  }
  //   reset to start of second triangle
  werdBot.ufEmPunktNachRechtsDreie(120);
  werdBot.graduusMoole(30);
  werdBot.ufEmPunktNachLinksDreie(60);
  werdBot.graduusMoole(30);
  werdBot.fertig();
}

void eifachiChriesi(void) {
  werdBot.linksKurveMoole(360);
  werdBot.ufEmPunktNachRechtsDreie(90);
  werdBot.graduusMoole(200);
  werdBot.ufEmPunktNachRechtsDreie(150);
  werdBot.graduusMoole(200);
  werdBot.ufEmPunktNachLinksDreie(90);
  werdBot.rechtsKurveMoole(360);
  werdBot.fertig();
}

void laessigiChriesi(void) {
  // start with the red pen
  werdBot.linksKurveMoole(360);
  // wait for 2 seconds, so you can change from the red pen to the green one!
  werdBot.warte(2);
  werdBot.ufEmPunktNachRechtsDreie(45);
  werdBot.bogeNachLinksMoole(30, 132.82 * 3);
  werdBot.ufEmPunktNachRechtsDreie(180);
  werdBot.bogeNachLinksMoole(30, 132.82 * 3);
  // change back to the green pen
  werdBot.warte(2);
  werdBot.ufEmPunktNachLinksDreie(45);
  werdBot.rechtsKurveMoole(360);
  werdBot.fertig();
}
/* draw an outgoing spiral based on half circles for runde turns */
void schnaegg(int runde = 5) {
  for (int i = 1; i < runde * 2; i++) {
    werdBot.bogeNachLinksMoole(180.0, 20.0*i);
  }
  werdBot.fertig();
}

/* try to draw something the resembles the tutti.ch t-logo */
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

/*
 * draw the home of st. nicolaus.
 * SPOILER ALERT: it shows you the solution to the problem ;)
 */
void huesli(float width) {
  // floor
  werdBot.ufEmPunktNachLinksDreie(90.0);
  werdBot.graduusMoole(width);
  // wall left
  werdBot.ufEmPunktNachRechtsDreie(90.0);
  werdBot.graduusMoole(width);
  // wall top
  werdBot.ufEmPunktNachRechtsDreie(90.0);
  werdBot.graduusMoole(width);
  // wall right
  werdBot.ufEmPunktNachRechtsDreie(90.0);
  werdBot.graduusMoole(width);
  // first diagonal
  werdBot.ufEmPunktNachRechtsDreie(135.0);
  werdBot.graduusMoole(sqrt(2*(width*width)));
  // roofs
  werdBot.ufEmPunktNachRechtsDreie(90.0);
  werdBot.graduusMoole(sqrt(2*((width/2)*(width/2))));
  werdBot.ufEmPunktNachRechtsDreie(90.0);
  werdBot.graduusMoole(sqrt(2*((width/2)*(width/2))));
  // final diagonal
  werdBot.ufEmPunktNachRechtsDreie(90.0);
  werdBot.graduusMoole(sqrt(2*(width*width)));
}

/*
 * calibrate by drawing a figure 8
 */
void calibrate(void) {
  werdBot.linksKurveMoole(360);
  werdBot.rechtsKurveMoole(360);
  werdBot.fertig();
}
