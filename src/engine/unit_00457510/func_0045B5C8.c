#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0045B190(void *);                          /* extern */

struct func_0045B5C8_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};
struct func_0045B5C8_arg1 {
    s32 unk0;
    char pad4[0x4];
    s32 unk8;
};

void func_0045B5C8(struct func_0045B5C8_arg0 *arg0, struct func_0045B5C8_arg1 *arg1) {
    arg0->unk4 = (s32) (arg1->unk8 - arg1->unk0);
    arg0->unk0 = func_0045B190(arg1);
    arg0->unk8 = func_0045B190(arg1);
}
