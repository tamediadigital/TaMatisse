#include <Arduino.h>
#include "TaMatisse.h"
#include "Prototypes.h"

TaMatisse werdBot;

// list of built-in functions

// painting functions
// werdBot.graduusMoole(mm);
// werdBot.linksKurveMoole(deg);
// werdBot.rechtsKurveMoole(deg);
// werdBot.bogeNachLinksMoole(deg, mm);
// werdBot.bogeNachRechtsMoole(deg, mm);

// non-painting functions
// werdBot.ufEmPunktNachLinksDreie(deg);
// werdBot.ufEmPunktNachRechtsDreie(deg);
// werdBot.warte();
// werdBot.fertig();

// phyiscal constant
// werdBot.radAbstand();

void setup() {

}

void loop() {
  werdBot.graduusMoole(40);
  werdBot.graduusMoole(-40);

}