#include "types.h"
#include "gt4/RaceLanControlManager.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00337FB8(s32);                         /* extern */
s32 func_00338088(s32, s32);                    /* extern */

void RaceLanControlManager__virtual_06(void *arg0) {
    s32 temp_v0;

    func_00337FB8(((struct RaceLanControlManager *)arg0)->unk64);
    if (((struct RaceLanControlManager *)arg0)->unk68 != 0) {
        temp_v0 = ((struct RaceLanControlManager *)arg0)->unk6C - 1;
        ((struct RaceLanControlManager *)arg0)->unk6C = temp_v0;
        if (temp_v0 != -1) {
            ((struct RaceLanControlManager *)arg0)->unk50 = (s32) (((struct RaceLanControlManager *)arg0)->unk50 - 1);
            return;
        }
        ((struct RaceLanControlManager *)arg0)->unk6C = 1;
        goto block_5;
    }
block_5:
    func_00338088(((struct RaceLanControlManager *)arg0)->unk64, ((struct RaceLanControlManager *)arg0)->unk50);
}
