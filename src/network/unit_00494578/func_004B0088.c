#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00572CD8();                            /* extern */

extern char D_00689028[];
struct func_004B0088_arg0 {
    char pad0[0x44];
    s32 unk44;
};

void func_004B0088(struct func_004B0088_arg0 *arg0) {
    func_00572CD8();
    arg0->unk44 = (s32)D_00689028;
}
