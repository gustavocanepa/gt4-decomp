#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00566EA8(s32, s32, void *);            /* extern */

extern char D_00655290[];
struct func_00556870_arg0 {
    char pad0[0x5C];
    s32 unk5C;
};

s32 func_00556870(struct func_00556870_arg0 *arg0) {
    s8 sp[0x10];
    return func_00566EA8((s32)D_00655290, arg0->unk5C, sp) == 0;
}
