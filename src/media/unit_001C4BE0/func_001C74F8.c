#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_0046C098(void *, s32);                     /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char D_00660DC8[];
struct func_001C74F8_arg0 {
    char pad0[0x8E8];
    s32 unk8E8;
};

void func_001C74F8(struct func_001C74F8_arg0 *arg0, s32 arg1) {
    arg0->unk8E8 = (s32)D_00660DC8;
    func_0046C098(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
