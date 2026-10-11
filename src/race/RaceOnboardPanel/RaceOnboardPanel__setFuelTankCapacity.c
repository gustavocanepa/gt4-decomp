#include "types.h"
#include "gt4/RaceOnboardPanel.h"
void *memcpy(void *, const void *, unsigned int);

void RaceOnboardPanel__setFuelTankCapacity(struct RaceOnboardPanel *arg0, f32 fparg0) {
    arg0->unk30 = fparg0;
}
