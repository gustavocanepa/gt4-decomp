#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00391E80(s32);                         /* extern */
s32 func_00460758(s32);                         /* extern */

struct func_003BA8B8_arg0 {
    char pad0[0x24698];
    s32 unk24698;
    char pad2469C[0x4];
    s32 unk246A0;
    s32 unk246A4;
};

void func_003BA8B8(struct func_003BA8B8_arg0 *arg0, s32 arg1) {
    if ((arg0->unk246A0 != 0) && (arg0->unk24698 != 0) && (arg0->unk246A4 != arg1)) {
        func_00391E80(arg1 ^ 1);
        func_00460758(arg1);
        arg0->unk246A4 = arg1;
    }
}
