#include "types.h"
#include "gt4/RacePause.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003EC0B0(s32, s32, s32, s32);  /* extern */

s32 RacePause__virtual_04(struct RacePause *arg0) {
    s32 temp_v0;

    if (arg0->unkC != 0) {
        temp_v0 = arg0->unk18;
        if (temp_v0 != 0) {
            func_003EC0B0(temp_v0, arg0->unk14, 0x80FFFFFF, 0);
        }
    }
}
