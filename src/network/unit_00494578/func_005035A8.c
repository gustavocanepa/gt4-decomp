/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005783A0(s32);                         /* extern */
s32 func_005AD9A0(s32, s32);                /* extern */

struct func_005035A8_arg0 {
    char pad0[0x2180];
    s32 unk2180;
    s32 unk2184;
};

void func_005035A8(struct func_005035A8_arg0 *arg0) {
    func_005AD9A0(2, arg0->unk2184);
    func_005783A0(arg0->unk2180);
}
