#include "types.h"
#include "gt4/DynamicsConductorBattle2P.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0034C210(void *);                          /* extern */
s32 func_003C0E78(s32);                             /* extern */
s32 func_003F12A0(void *);                          /* extern */

void DynamicsConductorBattle2P__virtual_13(struct DynamicsConductorBattle2P *arg0) {
    s32 temp_s1;

    if (func_003C0E78(arg0->unk0) != 0) {
        temp_s1 = func_003F12A0(arg0);
        if (func_0034C210(arg0) != 0) {
            arg0->unkF8C0 = temp_s1;
        }
        arg0->unkF898 = (s32) (temp_s1 - arg0->unkF8C0);
    }
}
