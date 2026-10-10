#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern "C" {
s32 RaceBasic__notifyChangeSpecMode();                            /* extern */
s32 RaceInput__setRunMode(void *, s32);                 /* extern */

struct RaceFreeRun__virtual_18_arg0 {
    char pad0[0xCC8];
    s32 unkCC8;
};

void RaceSolitaire__notifyChangeSpecMode(char *arg0) {
    RaceBasic__notifyChangeSpecMode();
    RaceInput__setRunMode(arg0 + 0xE48C, ((struct RaceFreeRun__virtual_18_arg0 *)arg0)->unkCC8);
    RaceInput__setRunMode(arg0 + 0xE84C, ((struct RaceFreeRun__virtual_18_arg0 *)arg0)->unkCC8);
}

}
