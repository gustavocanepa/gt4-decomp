#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
s32 RaceNetBattle__virtual_18();                            /* extern */
s32 func_00426BF8(void *, s32);                 /* extern */

struct RaceFreeRun__virtual_18_arg0 {
    char pad0[0xCC8];
    s32 unkCC8;
};

void RaceFreeRun__virtual_18(char *arg0) {
    RaceNetBattle__virtual_18();
    func_00426BF8(arg0 + 0xE48C, ((struct RaceFreeRun__virtual_18_arg0 *)arg0)->unkCC8);
    func_00426BF8(arg0 + 0xE84C, ((struct RaceFreeRun__virtual_18_arg0 *)arg0)->unkCC8);
}

}
