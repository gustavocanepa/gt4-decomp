#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00501180(void *);                      /* extern */
s32 func_00503070(void *, void *);              /* extern */

struct func_00503008_arg0 {
    char pad0[0x208];
    s32 unk208;
    char pad20C[0x8];
    s32 unk214;
};

s32 func_00503008(void *arg0) {
    if ((((struct func_00503008_arg0 *)arg0)->unk214 == 0) && (((struct func_00503008_arg0 *)arg0)->unk208 != 0)) {
        func_00501180(arg0 + 0xB8);
        func_00503070(arg0, arg0 + 0x1D8);
        func_00503070(arg0, arg0 + 0x1E4);
        func_00503070(arg0, arg0 + 0x1F0);
    }
}
