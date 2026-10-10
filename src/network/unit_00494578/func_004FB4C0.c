#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00500948(void *);                      /* extern */
s32 func_00505F08(void *);                      /* extern */
s32 func_0050D028(void *);                      /* extern */
s32 func_0050D088(void *);                      /* extern */

struct func_004FB4C0_arg0 {
    char pad0[0x5E4];
    s32 unk5E4;
    s32 unk5E8;
    s32 unk5EC;
    s32 unk5F0;
    char pad5F4[0x440];
    s32 unkA34;
};

s32 func_004FB4C0(void *arg0) {
    s32 temp_v0;

    temp_v0 = ((struct func_004FB4C0_arg0 *)arg0)->unkA34 - 1;
    ((struct func_004FB4C0_arg0 *)arg0)->unkA34 = temp_v0;
    if (temp_v0 <= 0) {
        ((struct func_004FB4C0_arg0 *)arg0)->unkA34 = 0x708;
        if (((struct func_004FB4C0_arg0 *)arg0)->unk5E4 != 0) {
            func_0050D028(arg0 + 0x5F4);
        }
        if (((struct func_004FB4C0_arg0 *)arg0)->unk5E8 != 0) {
            func_0050D088(arg0 + 0x70C);
        }
        if (((struct func_004FB4C0_arg0 *)arg0)->unk5EC != 0) {
            func_00505F08(arg0 + 0x88C);
        }
        if (((struct func_004FB4C0_arg0 *)arg0)->unk5F0 != 0) {
            func_00500948(arg0);
        }
    }
}
