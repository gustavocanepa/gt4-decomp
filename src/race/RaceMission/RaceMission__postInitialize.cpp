#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern "C" {
s32 CarIconMaker__structor_1(s32, s32);                    /* extern */
s32 RaceTrainingBase__postInitialize();                            /* extern */

struct RaceMission__virtual_39_arg0 {
    char pad0[0x6C];
    s32 unk6C;
};

void RaceMission__postInitialize(char *arg0) {
    RaceTrainingBase__postInitialize();
    CarIconMaker__structor_1((s32)(arg0 + 0x22748), ((struct RaceMission__virtual_39_arg0 *)arg0)->unk6C);
}

}
