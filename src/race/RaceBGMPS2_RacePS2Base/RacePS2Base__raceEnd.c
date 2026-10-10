#include "types.h"
#include "gt4/RacePS2Base.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void RaceBase__raceEnd();                            /* extern */

void RacePS2Base__raceEnd(struct RacePS2Base *arg0) {
    RaceBase__raceEnd();
    arg0->unkD80 = 1;
}
