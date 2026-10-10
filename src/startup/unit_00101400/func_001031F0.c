#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00574D78(void *);                      /* extern */

struct func_001031F0_arg0 {
    s32 unk0;
    s32 unk4;
    char pad8[0x60];
    s32 unk68;
};

void func_001031F0(void *arg0, s32 arg1) {
    ((struct func_001031F0_arg0 *)arg0)->unk0 = arg1;
    ((struct func_001031F0_arg0 *)arg0)->unk4 = 1;
    func_00574D78(arg0 + 8);
    func_00574D78(arg0 + 0x38);
    ((struct func_001031F0_arg0 *)arg0)->unk68 = 0;
}
