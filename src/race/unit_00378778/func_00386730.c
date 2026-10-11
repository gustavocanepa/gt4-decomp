#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00407208(s32, s32);                    /* extern */
s32 func_005F63B0();                            /* extern */
s32 func_005F63E8(s32, s32);                    /* extern */

struct func_00386730_arg0 {
    char pad0[0x360];
    s32 unk360;
    s32 unk364;
    s32 unk368;
};
struct func_00386730_arg1 {
    char pad0[0x360];
    s32 unk360;
    s32 unk364;
    s32 unk368;
};

void *func_00386730(void *arg0, void *arg1) {
    func_005F63B0();
    func_005F63E8(arg0 + 0x40, arg1 + 0x40);
    func_00407208(arg0 + 0x160, arg1 + 0x160);
    func_00407208(arg0 + 0x260, arg1 + 0x260);
    ((struct func_00386730_arg0 *)arg0)->unk360 = (s32) ((struct func_00386730_arg1 *)arg1)->unk360;
    ((struct func_00386730_arg0 *)arg0)->unk364 = (s32) ((struct func_00386730_arg1 *)arg1)->unk364;
    ((struct func_00386730_arg0 *)arg0)->unk368 = (s32) ((struct func_00386730_arg1 *)arg1)->unk368;
    return arg0;
}
