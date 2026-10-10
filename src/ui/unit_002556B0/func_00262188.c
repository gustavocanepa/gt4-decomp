#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 MintReader__structor_6(s32);                             /* extern */
void func_00266458(void *, s32, s32);        /* extern */

struct func_00262188_arg0 {
    char pad0[0x98];
    s32 unk98;
    s32 unk9C;
};

void func_00262188(struct func_00262188_arg0 *arg0, s32 arg1) {
    if (!(arg0->unk9C & 0x100)) {
        arg0->unk98 = (s32) (arg0->unk98 | 0xF0);
    }
    func_00266458(arg0, 1, MintReader__structor_6(arg1));
    arg0->unk9C = (s32) (arg0->unk9C | 0x100);
}
