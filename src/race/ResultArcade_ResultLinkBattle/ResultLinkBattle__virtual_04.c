#include "types.h"
#include "gt4/ResultLinkBattle.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_003EC0B0(s32, s32, s32, s32);  /* extern */

s32 ResultLinkBattle__virtual_04(struct ResultLinkBattle *arg0) {
    s32 temp_a1;
    s32 temp_v1;

    if (arg0->unk10 != 0) {
        temp_v1 = arg0->unk54;
        if (temp_v1 != 0) {
            temp_a1 = arg0->unk5C;
            if ((temp_a1 != 0) && (arg0->unk0 != 0)) {
                func_003EC0B0(temp_v1, temp_a1, 0x80FFFFFF, 0);
            }
        }
    }
}
