#include <Arduino.h>
#include "TaMatisse.h"
#include "Prototypes.h"

TaMatisse werdBot;

void setup()
{
   // Serial.begin(115200);
   delay(1000);
}

void loop()
{
   // Heart
   // werdBot.graduusMoole(140);
   // werdBot.bogeNachRechtsMoole(180, 70);
   // werdBot.ufEmPunktNachLinksDreie(90);
   // werdBot.bogeNachRechtsMoole(180, 70);
   // werdBot.graduusMoole(140);
   // werdBot.ufEmPunktNachLinksDreie(135);
   // werdBot.graduusMoole(100);
   werdBot.linksKurveMoole(180);
   werdBot.rechtsKurveMoole(180);
}