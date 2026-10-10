#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern "C" {
s32 func_004A7BA8();                                /* extern */
s32 func_004A7C60();                                /* extern */
s32 func_004A7CA0(void *, void *, void *, void *); /* extern */
s32 func_004A7CE0(void *, void *, void *, void *); /* extern */
s32 func_004AA6B8(s32);                         /* extern */

struct func_00105F68_arg0 {
    s32 unk0;
    char pad4[0x24];
    s32 unk28;
    s32 unk2C;
    char pad30[0x4];
    s32 unk34;
};

void func_00105F68(char *arg0) {
    if (((struct func_00105F68_arg0 *)arg0)->unk34 != 0) {
        func_004AA6B8(((struct func_00105F68_arg0 *)arg0)->unk0);
    }
    func_004A7CA0(arg0, arg0 + 4, arg0 + 8, arg0 + 0xC);
    ((struct func_00105F68_arg0 *)arg0)->unk28 = func_004A7C60();
    ((struct func_00105F68_arg0 *)arg0)->unk2C = func_004A7BA8();
    func_004A7CE0(arg0 + 0x10, arg0 + 0x14, arg0 + 0x18, arg0 + 0x1C);
}

}
