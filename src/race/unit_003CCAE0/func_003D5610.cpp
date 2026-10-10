#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern "C" {
s32 func_003D50C8(void *, s32, s32, s32, s32, s32); /* extern */

struct func_003D5610_arg0 {
    char pad0[0x12CC];
    s32 unk12CC;
    s32 unk12D0;
};

void func_003D5610(char *arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_003D50C8(arg0 + (arg1 * 0x320), ((struct func_003D5610_arg0 *)arg0)->unk12D0, arg1, ((struct func_003D5610_arg0 *)arg0)->unk12CC, arg2, arg3);
}

}
