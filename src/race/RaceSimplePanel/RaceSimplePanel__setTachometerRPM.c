#include "types.h"
#include "gt4/RaceSimplePanel.h"
void *memcpy(void *, const void *, unsigned int);

void RaceSimplePanel__setTachometerRPM(struct RaceSimplePanel *arg0, f32 fparg0) {
    arg0->unk118 = fparg0;
}
