#include "types.h"
#include "gt4/RaceTraining.h"
void *memcpy(void *, const void *, unsigned int);

s32 RaceMission__virtual_152();                            /* extern */

void RaceTraining__virtual_152(struct RaceTraining *arg0, s32 arg1) {
    RaceMission__virtual_152();
    arg0->unk137E8 = arg1;
}
