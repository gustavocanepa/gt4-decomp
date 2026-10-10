/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004EFAA8();                            /* extern */
s32 func_005016D8(void *);                      /* extern */
s32 func_00502FA8(void *);                      /* extern */
s32 func_00578908(s32);                         /* extern */
s32 func_00578AF0(s32);                         /* extern */

struct func_00502428_arg0 {
    char pad0[0x20C];
    s32 unk20C;
    char pad210[0x4];
    s32 unk214;
};

void func_00502428(struct func_00502428_arg0 *arg0) {
    s32 temp_s0;

    if (arg0->unk214 != 0) {
        arg0->unk20C = 1;
        func_004EFAA8();
        temp_s0 = arg0->unk214;
        arg0->unk214 = 0;
        func_00578908(temp_s0);
        func_00578AF0(temp_s0);
        func_005016D8(arg0);
        func_00502FA8(arg0);
    }
}
