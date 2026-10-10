#include "types.h"
#include "gt4/RaceTrainingBase.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0033CF48();                                /* extern */
s32 RacePause__structor_0(void *);                      /* extern */
s32 func_003C31C8(void *, void *);              /* extern */
s32 RaceSinglePlayer__structor_0();                            /* extern */
s32 RaceMission__virtual_152(void *, s32);             /* extern */

extern char RaceTrainingBase__vtable[];
struct RaceTrainingBase__structor_0_temp_s0 {
    char pad0[0x28];
    s32 unk28;
};

void RaceTrainingBase__structor_0(void *arg0) {
    struct RaceTrainingBase__structor_0_temp_s0 *temp_s0;

    RaceSinglePlayer__structor_0();
    temp_s0 = arg0 + 0x125C0;
    ((struct RaceTrainingBase *)arg0)->unk64 = (s32)RaceTrainingBase__vtable;
    RacePause__structor_0(temp_s0);
    if (func_0033CF48() == 0) {
        temp_s0->unk28 = 1;
        func_003C31C8(temp_s0, arg0 + 0xE350);
    }
    RaceMission__virtual_152(arg0, 0);
    ((struct RaceTrainingBase *)arg0)->unkD68 = 3;
}
