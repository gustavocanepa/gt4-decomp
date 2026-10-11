#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
s32 RaceBase__postInitialize();                            /* extern */
s32 CarIconMaker__structor_1(s32, s32);                    /* extern */

struct RaceFreeRun__virtual_39_arg0 {
    char pad0[0x6C];
    s32 unk6C;
};

void RaceFreeRun__postInitialize(char *arg0) {
    RaceBase__postInitialize();
    CarIconMaker__structor_1((s32)(arg0 + 0x1F2A0), ((struct RaceFreeRun__virtual_39_arg0 *)arg0)->unk6C);
}

}
