/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

s32 func_005A6AB0(void *, s32, s32);        /* extern */

struct func_004ED660_arg0 {
    char pad0[0x50];
    void *unk50;
};
struct func_004ED660_temp_v1 {
    char pad0[0x1320];
    s8 unk1320;
};

void func_004ED660(struct func_004ED660_arg0 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    struct func_004ED660_temp_v1 *temp_v1;

    M2C_FIELD(arg0->unk50, s8 *, 0x300) = 0;
    M2C_FIELD(arg0->unk50, s8 *, 0x400) = 0;
    M2C_FIELD(arg0->unk50, s8 *, 0x500) = 0;
    if (arg1 == 0) {
        if (arg2 != 0) {
            func_005A6AB0(arg0->unk50 + 0x300, arg2, 0x100);
        }
        if (arg3 != 0) {
            func_005A6AB0(arg0->unk50 + 0x400, arg3, 0x100);
        }
        if (arg4 != 0) {
            func_005A6AB0(arg0->unk50 + 0x500, arg4, 0x100);
        }
    }
    M2C_FIELD(arg0->unk50, s8 *, 0xB00) = 0;
    M2C_FIELD(arg0->unk50, s8 *, 0xC00) = 0;
    M2C_FIELD(arg0->unk50, s8 *, 0xD00) = 0;
    M2C_FIELD(arg0->unk50, s32 *, 0x1300) = 3;
    M2C_FIELD(arg0->unk50, s32 *, 0x1304) = -1;
    M2C_FIELD(arg0->unk50, s32 *, 0x1308) = -1;
    temp_v1 = arg0->unk50;
    if (arg1 != 0) {
        temp_v1->unk1320 = 1;
    } else {
        temp_v1->unk1320 = 0;
    }
    M2C_FIELD(arg0->unk50, s8 *, 0x1323) = 0;
    M2C_FIELD(arg0->unk50, s8 *, 0x1324) = 0;
    M2C_FIELD(arg0->unk50, s8 *, 0x1325) = -1;
    M2C_FIELD(arg0->unk50, s8 *, 0x1326) = -1;
    M2C_FIELD(arg0->unk50, s8 *, 0x1327) = -1;
    M2C_FIELD(arg0->unk50, s8 *, 0x1328) = -1;
}
