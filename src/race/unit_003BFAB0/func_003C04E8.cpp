#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
#include "m2c_macros.h"

extern "C" {
s32 func_0034C190(s32, s32);                    /* extern */
s32 func_003B76F0(void *, s32, s32, s32); /* extern */
s32 func_003F37E8(s32);                             /* extern */

struct func_003C04E8_arg0 {
    char pad0[0x84];
    void *unk84;
    char pad88[0x34];
    s32 unkBC;
    s32 unkC0;
    char padC4[0x4];
    f32 unkC8;
    s32 unkCC;
    char padD0[0x4];
    f32 unkD4;
};

void func_003C04E8(char *arg0, f32 fparg0) {
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;

    if ((((struct func_003C04E8_arg0 *)arg0)->unkBC == 0) && (((struct func_003C04E8_arg0 *)arg0)->unkC0 != 0) && (func_003F37E8(func_0034C190(M2C_FIELD(((struct func_003C04E8_arg0 *)arg0)->unk84, s32 *, 0x70), 0)) == 0)) {
        temp_f1 = ((struct func_003C04E8_arg0 *)arg0)->unkC8 - (fparg0 * 0x1.e000000000000p+5f);
        ((struct func_003C04E8_arg0 *)arg0)->unkC8 = temp_f1;
        if (temp_f1 <= 0x0.0p+0f) {
            ((struct func_003C04E8_arg0 *)arg0)->unkC0 = 0;
            func_003B76F0(arg0 + 0xF4, 7, 0, 0);
        }
        if ((((struct func_003C04E8_arg0 *)arg0)->unkC8 <= 0x1.6800000000000p+7f) && (((struct func_003C04E8_arg0 *)arg0)->unkCC == 0)) {
            ((struct func_003C04E8_arg0 *)arg0)->unkCC = 1;
            func_003B76F0(arg0 + 0xF4, 9, 0, 1);
        }
    }
    temp_f0 = ((struct func_003C04E8_arg0 *)arg0)->unkD4;
    if (temp_f0 > 0x0.0p+0f) {
        temp_f0_2 = temp_f0 - fparg0;
        ((struct func_003C04E8_arg0 *)arg0)->unkD4 = temp_f0_2;
        if (temp_f0_2 <= 0x0.0p+0f) {
            ((struct func_003C04E8_arg0 *)arg0)->unkD4 = 0x0.0p+0f;
            func_003B76F0(arg0 + 0xF4, 1, 0, 0);
        }
    }
}

}
