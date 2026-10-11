#include "types.h"
#include "gt4/RaceLanBattle.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003378E0(void *, s32);                         /* extern */

void *RaceLanBattle__virtual_69(void *arg0) {
    s32 var_v1;

    if (func_003378E0(arg0, 0) != 0) {
        var_v1 = ((struct RaceLanBattle *)arg0)->unkF388;
    } else {
        var_v1 = ((struct RaceLanBattle *)arg0)->unkE444;
    }
    return arg0 + (var_v1 * 0x214) + 0xE50C;
}
