#include "types.h"
#include "gt4/RaceBase.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_003B76F0(void *, s32, s32, s32); /* extern */

struct RaceBase__virtual_78_temp_v1 {
    char pad0[0xB4];
    s32 unkB4;
};

s32 RaceBase__raceStart(struct RaceBase *arg0) {
    void *temp_v1;

    if (arg0->unkD4C == 0) {
        temp_v1 = arg0->unk6C;
        arg0->unkD4C = 1;
        if (((struct RaceBase__virtual_78_temp_v1 *)temp_v1)->unkB4 != -1) {
            func_003B76F0(temp_v1 + 0xF4, 0x18, 0xC, 0);
        }
    }
}
