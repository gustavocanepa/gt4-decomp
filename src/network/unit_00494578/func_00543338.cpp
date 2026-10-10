extern "C" {
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

char *func_00538988(...) throw();
s32 func_005428E8(...) throw();
s32 func_005A4724(...) throw();
s32 func_005A48D8(...) throw();

struct func_00543338_temp_s0 {
    char pad0[0x2C];
    s32 unk2C;
};

s32 func_00543338(s32 arg0, s32 arg1, s32 arg2) {
    char *temp_s0;

    temp_s0 = func_00538988();
    if (arg2 != 0) {
        if ((temp_s0 != NULL) && (func_005428E8(((struct func_00543338_temp_s0 *)temp_s0)->unk2C) == 0)) {
            func_005A4724(arg2, ((struct func_00543338_temp_s0 *)temp_s0)->unk2C, 0x40);
            return 0;
        }
        func_005A48D8(arg2, 0, 0x40);
        goto block_6;
    }
block_6:
    return -1;
}

}
