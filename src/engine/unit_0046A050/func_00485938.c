#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_005C1628(void *);                      /* extern */

extern char D_00688B40[];
struct func_00485938_arg0 {
    char pad0[0x3C];
    s32 unk3C;
};

void func_00485938(struct func_00485938_arg0 *arg0, s32 arg1) {
    arg0->unk3C = (s32)D_00688B40;
    func_00574DA8(arg0, 2);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
