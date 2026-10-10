/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005A48D8(s32, s32, s32);       /* extern */

struct func_004F8D00_arg0 {
    char pad0[0x2150];
    s32 unk2150;
};

void func_004F8D00(void *arg0) {
    func_005A48D8(arg0 + 0x1020, 0, 0x1130);
    ((struct func_004F8D00_arg0 *)arg0)->unk2150 = 0xFFFFFF;
    func_005A48D8(arg0 + 0x2154, 0, 0x2C);
}
