#include <Arduino.h>
#include "TaMatisse.h"

// Simple example for driving the TaMatisse, our little painting bot around
TaMatisse werdBot;

void setup() {
}


void loop() {
  // triangle
  for (int i=0; i<3; i++) {
    werdBot.graduusMoole(90);
    werdBot.ufEmPunktNachRechtsDreie(120);
  }
  werdBot.ufEmPunktNachRechtsDreie(180);
  werdBot.graduusMoole(30);
  werdBot.ufEmPunktNachRechtsDreie(120);
  werdBot.graduusMoole(30);

}
