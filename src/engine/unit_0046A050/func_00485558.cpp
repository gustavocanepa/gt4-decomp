#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00472F90(s32, s32, s32, s32, s32); /* extern */

struct func_00485558_arg0 {
    s32 unk0;
    char pad4[0x4];
    s32 unk8;
    s32 unkC;
};

void func_00485558(void *arg0) {
    s32 temp_v1;

    temp_v1 = ((struct func_00485558_arg0 *)arg0)->unk8;
    func_00472F90(((struct func_00485558_arg0 *)arg0)->unk0, (s32) ((s32) (((struct func_00485558_arg0 *)arg0)->unkC - temp_v1) >> 2) / 6, temp_v1, 0, 0);
}
