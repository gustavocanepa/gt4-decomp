#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char D_00689DD8[];
struct func_005778F8_arg0 {
    s32 unk0;
    s32 unk4;
};

s32 func_005778F8(struct func_005778F8_arg0 *arg0, s32 arg1) {
    arg0->unk0 = arg1;
    arg0->unk4 = (s32)D_00689DD8;
}
