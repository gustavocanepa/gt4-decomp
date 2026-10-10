#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_001CC1C8(s32 *, void *);
void func_001CC388(s32 *, s32);
typedef struct { u8 pad[0x30]; s32 x30; s32 *a[1]; } T;
s32 func_001D33B0(T *arg0, s32 arg1) {
    s8 sp[0x10];
    s32 *temp_s0;
    s8 *e = (s8 *)arg0 + arg1 * 4; temp_s0 = *(s32 **)(e + 0x34);
    if (*temp_s0 < 0) {
        func_001CC388(temp_s0, arg0->x30);
        func_001CC1C8(temp_s0, sp);
        return 1;
    }
    return 0;
}
