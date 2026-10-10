#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_004A53F8();                            /* extern */

struct func_0042C818_arg0 {
    char pad0[0x8];
    s32 unk8;
};

void func_0042C818(struct func_0042C818_arg0 *arg0) {
    func_004A53F8();
    arg0->unk8 = (s32) (arg0->unk8 + 1);
}
