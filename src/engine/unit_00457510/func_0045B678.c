#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0045B5C8();                            /* extern */

struct func_0045B678_arg0 {
    char pad0[0x4];
    s32 unk4;
};
struct func_0045B678_arg1 {
    s32 unk0;
    char pad4[0x4];
    s32 unk8;
};

void func_0045B678(struct func_0045B678_arg0 *arg0, struct func_0045B678_arg1 *arg1) {
    s32 frag1;
    func_0045B5C8();
    frag1 = arg0->unk4;
    arg1->unk8 = (s32) (arg1->unk0 + frag1);
}
