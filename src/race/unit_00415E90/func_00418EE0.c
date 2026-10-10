#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00418F88(s32);                         /* extern */
s32 func_0041C1C8();                            /* extern */

struct func_00418EE0_arg0 {
    char pad0[0x200];
    s32 unk200;
};

void func_00418EE0(void *arg0) {
    func_0041C1C8();
    func_00418F88(arg0 + 0xE0);
    ((struct func_00418EE0_arg0 *)arg0)->unk200 = 0;
}
