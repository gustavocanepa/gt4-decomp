#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_0011DB60_arg0 {
    char pad0[0x40008];
    s32 unk40008;
};

void func_0011DB60(void *arg0) {
    func_005A48D8(arg0, 0, 0x40000);
    func_005A48D8(arg0 + 0x40000, 0, 8);
    ((struct func_0011DB60_arg0 *)arg0)->unk40008 = 0;
}
