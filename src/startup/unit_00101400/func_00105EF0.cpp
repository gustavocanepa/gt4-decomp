#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00498828(void *, s32);                 /* extern */
s32 func_00499508(void *);                      /* extern */
s32 func_004A2038(s32);                     /* extern */
s32 func_004A4910();                            /* extern */
s32 func_004AA558(s32);                             /* extern */
s32 func_004AA6B8(s32);                         /* extern */

struct func_00105EF0_arg0 {
    s32 unk0;
    char pad4[0x30];
    s32 unk34;
};
struct func_00105EF0_arg1 {
    char pad0[0x12];
    u16 unk12;
};

void func_00105EF0(void *arg0, void *arg1) {
    s32 temp_v0;

    if (((struct func_00105EF0_arg0 *)arg0)->unk34 != 0) {
        func_004AA6B8(((struct func_00105EF0_arg0 *)arg0)->unk0);
    }
    temp_v0 = func_004AA558(((struct func_00105EF0_arg1 *)arg1)->unk12 << 6);
    ((struct func_00105EF0_arg0 *)arg0)->unk34 = 1;
    ((struct func_00105EF0_arg0 *)arg0)->unk0 = temp_v0;
    func_00498828(arg1, temp_v0);
    func_00499508(arg1);
    func_004A2038(1);
    func_004A4910();
}
