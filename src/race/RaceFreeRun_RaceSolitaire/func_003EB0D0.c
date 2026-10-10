#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

void *func_00346A28(void *);                        /* extern */

struct func_003EB0D0_temp_v0 {
    char pad0[0x10];
    s32 unk10;
};
struct func_003EB0D0_temp_v0_2 {
    char pad0[0x10];
    s32 unk10;
};
struct func_003EB0D0_temp_v0_3 {
    char pad0[0x10];
    s32 unk10;
};
struct func_003EB0D0_temp_v0_4 {
    char pad0[0x10];
    s32 unk10;
};

struct func_003EB0D0_arg0 {
    char pad0[0x6C];
    void *unk6C;
    char pad70[0xE5EC];
    s32 unkE65C;
    char padE660[0x1DC];
    s32 unkE83C;
    char padE840[0x1DC];
    s32 unkEA1C;
    char padEA20[0x1DC];
    s32 unkEBFC;
    char padEC00[0x4FC];
    s32 unkF0FC;
    char padF100[0x4];
    s32 unkF104;
};

s32 func_003EB0D0(void *arg0) {
    s32 var_s2;
    struct func_003EB0D0_temp_v0 *temp_v0;
    struct func_003EB0D0_temp_v0_2 *temp_v0_2;
    struct func_003EB0D0_temp_v0_3 *temp_v0_3;
    struct func_003EB0D0_temp_v0_4 *temp_v0_4;

    ((struct func_003EB0D0_arg0 *)arg0)->unkEBFC = 1;
    var_s2 = 0;
    temp_v0 = func_00346A28(arg0 + 0xEB00);
    if (temp_v0 != NULL) {
        temp_v0->unk10 = 0x157529FF;
    }
    if (((struct func_003EB0D0_arg0 *)arg0)->unkF104 != 0) {
        ((struct func_003EB0D0_arg0 *)arg0)->unkE65C = 1;
        temp_v0_2 = func_00346A28(arg0 + 0xE560);
        if (temp_v0_2 != NULL) {
            temp_v0_2->unk10 = 0x157529FF;
        }
        ((struct func_003EB0D0_arg0 *)arg0)->unkE83C = 1;
        temp_v0_3 = func_00346A28(arg0 + 0xE740);
        if (temp_v0_3 != NULL) {
            temp_v0_3->unk10 = 0x157529FF;
        }
        ((struct func_003EB0D0_arg0 *)arg0)->unkEA1C = 1;
        temp_v0_4 = func_00346A28(arg0 + 0xE920);
        if (temp_v0_4 != NULL) {
            temp_v0_4->unk10 = 0x157529FF;
        }
        var_s2 = 1;
        *M2C_FIELD(M2C_FIELD(((struct func_003EB0D0_arg0 *)arg0)->unk6C, void **, 0x60), s32 **, 8) = ((struct func_003EB0D0_arg0 *)arg0)->unkF104;
        ((struct func_003EB0D0_arg0 *)arg0)->unkF104 = 0;
    }
    ((struct func_003EB0D0_arg0 *)arg0)->unkF0FC = 1;
    return var_s2;
}
