#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00430878(void *);                          /* extern */

struct func_003D6350_arg0 {
    char pad0[0x178];
    s32 unk178;
    s32 unk17C;
    s32 unk180;
    s32 unk184;
    s32 unk188;
};
struct func_003D6350_arg1 {
    char pad0[0x50];
    s32 unk50;
    s32 unk54;
    s32 unk58;
    s32 unk5C;
};

void func_003D6350(struct func_003D6350_arg0 *arg0, struct func_003D6350_arg1 *arg1) {
    arg0->unk178 = func_00430878(arg1);
    arg0->unk17C = (s32) arg1->unk54;
    arg0->unk180 = (s32) arg1->unk58;
    arg0->unk184 = (s32) arg1->unk50;
    arg0->unk188 = (s32) arg1->unk5C;
}
