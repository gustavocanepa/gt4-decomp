#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern "C" {
s32 func_00572D48(...);
s32 func_00573898(void *);                      /* extern */

struct func_00612E00_arg0 {
    char pad0[0x1C];
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    char pad28[0x18];
    s32 unk40;
};

void func_00612E00(char *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    ((struct func_00612E00_arg0 *)arg0)->unk40 = arg4;
    func_00572D48((s32) arg0, arg2, arg3);
    ((struct func_00612E00_arg0 *)arg0)->unk1C = arg1;
    ((struct func_00612E00_arg0 *)arg0)->unk20 = arg1;
    ((struct func_00612E00_arg0 *)arg0)->unk24 = (s32) (arg1 - 1);
    func_00573898(arg0);
}

}
