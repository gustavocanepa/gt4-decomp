#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00430298(s32);                             /* extern */

struct func_00436A00_arg0 {
    char pad0[0x10D8];
    s32 unk10D8;
};

void func_00436A00(struct func_00436A00_arg0 *arg0, s32 arg1) {
    arg0->unk10D8 = func_00430298(arg1);
}
