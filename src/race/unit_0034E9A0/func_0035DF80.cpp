#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern "C" {
s32 func_0034C190(s32, s32);                        /* extern */
s32 func_003B76F0(void *, s32, s32, s32);       /* extern */

struct func_0035DF80_arg0 {
    char pad0[0x84];
    void *unk84;
    char pad88[0x54];
    s32 unkDC;
};
struct func_0035DF80_temp_v0 {
    char pad0[0x632];
    u8 unk632;
};

void func_0035DF80(char *arg0, s32 arg1, s32 arg2, s32 arg3) {
    char *temp_v0;

    temp_v0 = (char *)(func_0034C190(M2C_FIELD(((struct func_0035DF80_arg0 *)arg0)->unk84, s32 *, 0x70), arg2) + 0x104);
    if ((((struct func_0035DF80_arg0 *)arg0)->unkDC == 0) && (((struct func_0035DF80_temp_v0 *)temp_v0)->unk632 == 0)) {
        func_003B76F0(arg0 + 0xF4, arg1, arg2, arg3);
    }
}

}
