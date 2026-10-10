/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00566070(s32, s32);                /* extern */

extern char D_006550F8[];
struct func_005566A8_arg0 {
    char pad0[0x5C];
    s32 unk5C;
};

void func_005566A8(struct func_005566A8_arg0 *arg0) {
    func_00566070((s32)D_006550F8, arg0->unk5C);
}
