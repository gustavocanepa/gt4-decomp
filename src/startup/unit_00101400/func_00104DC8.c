#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_00104148(void *, void *);
struct func_00104DC8_arg1 {
    char pad0[0xAC];
    s32 unkAC;
};
struct func_00104DC8_arg0 {
    char pad0[0x30];
    s32 unk30;
};

void func_00104DC8(struct func_00104DC8_arg0 *arg0, struct func_00104DC8_arg1 *arg1) {
    func_00104148(arg0, arg1);
    if (arg1->unkAC == 0) {
        arg0->unk30 = 0;
    }
}
