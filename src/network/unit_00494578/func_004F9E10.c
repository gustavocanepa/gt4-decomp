#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004F68C8();                                /* extern */
s32 func_004F8B28(void *, void *);                  /* extern */
s32 func_00576100(void *);                      /* extern */
s32 func_00576140(void *);                      /* extern */

struct func_004F9E10_arg0 {
    char pad0[0xEE0];
    s32 unkEE0;
    char padEE4[0x84];
    s32 unkF68;
};

s32 func_004F9E10(void *arg0) {
    if (func_004F68C8() != 0) {
        func_00576100(arg0);
        ((struct func_004F9E10_arg0 *)arg0)->unkF68 = 0;
        ((struct func_004F9E10_arg0 *)arg0)->unkEE0 = func_004F8B28(arg0 + 0xCD8, arg0 + 0xEE4);
        func_00576140(arg0);
    }
}
