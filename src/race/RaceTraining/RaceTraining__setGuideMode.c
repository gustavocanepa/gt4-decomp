#include "types.h"
#include "gt4/RaceTraining.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 RaceTrainingBase__setGuideMode();                            /* extern */

void RaceTraining__setGuideMode(struct RaceTraining *arg0, s32 arg1) {
    RaceTrainingBase__setGuideMode();
    arg0->unk137E8 = arg1;
}
