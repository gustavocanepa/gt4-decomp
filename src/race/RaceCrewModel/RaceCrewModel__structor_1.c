#include "types.h"
#include "gt4/RaceCrewModel.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 RaceDriverModel__structor_0();                            /* extern */

extern char RaceCrewModel__vtable[];
void RaceCrewModel__structor_1(struct RaceCrewModel *arg0) {
    RaceDriverModel__structor_0();
    arg0->unk7DC = (s32)RaceCrewModel__vtable;
}
