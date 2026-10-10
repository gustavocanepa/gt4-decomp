#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern char D_006A0508[];
struct func_003A0A20_arg0 {
    char pad0[0x4];
    void *unk4;
    s32 unk8;
};

s32 func_003A0A20(s32 arg0, s32 arg1) {
    if ((((struct func_003A0A20_arg0 *)arg0)->unk8 != 0) && (arg1 >= 0) && (arg1 < *M2C_FIELD(((struct func_003A0A20_arg0 *)arg0)->unk4, s32 **, 0x60))) {
        func_003A4308(arg0 + 0x1518, (s32)D_006A0508);
    }
}
