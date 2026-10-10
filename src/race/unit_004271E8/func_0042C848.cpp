#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004A5400();                            /* extern */

struct func_0042C848_arg0 {
    char pad0[0x8];
    s32 unk8;
};

void func_0042C848(void *arg0) {
    ((struct func_0042C848_arg0 *)arg0)->unk8 = (s32) (((struct func_0042C848_arg0 *)arg0)->unk8 - 1);
    func_004A5400();
}
