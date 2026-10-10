#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char D_0067E1F0[];
struct func_005F72E0_arg0 {
    s32 unk0;
    s32 unk4;
};

s32 func_005F72E0(struct func_005F72E0_arg0 *arg0, s32 arg1) {
    arg0->unk4 = arg1;
    arg0->unk0 = (s32)D_0067E1F0;
}
