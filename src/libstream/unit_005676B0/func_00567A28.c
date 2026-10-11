#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00567F10(s32);                         /* extern */

struct func_00567A28_arg0 {
    s32 unk0;
    char pad4[0xC];
    s32 unk10;
};

void func_00567A28(struct func_00567A28_arg0 *arg0) {
    if (arg0->unk10 != 0) {
        func_00567F10(arg0->unk0);
    }
}
