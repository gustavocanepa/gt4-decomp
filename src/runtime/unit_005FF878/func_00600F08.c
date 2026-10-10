#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00600F08_arg0 {
    char pad0[0xA58];
    s32 unkA58;
};

s32 func_00600F08(struct func_00600F08_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unkA58;
    arg0->unkA58 = 0;
    return temp_v0;
}
