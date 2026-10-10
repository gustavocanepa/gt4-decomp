#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0043A3F8();                            /* extern */

extern char D_00687AA0[];
struct func_004338F8_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

void func_004338F8(struct func_004338F8_arg0 *arg0) {
    func_0043A3F8();
    arg0->unk8 = 0;
    arg0->unk4 = 0;
    arg0->unk0 = (s32)D_00687AA0;
}
