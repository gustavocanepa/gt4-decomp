#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00427778(s32);                             /* extern */
s32 func_00427E18(void *, s32);                 /* extern */

struct func_00427E60_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void func_00427E60(struct func_00427E60_arg0 *arg0) {
    func_00427E18(arg0, func_00427778(arg0->unk4));
}
