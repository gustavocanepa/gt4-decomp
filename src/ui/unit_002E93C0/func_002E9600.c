#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct mDBox {
    s32 unk0;
    void * unk4;
    s32 unk8;
    void * unkC;
    s32 unk10;
    s32 unk14;
    char unk_18[0x10];
    s32 unk28;
    s32 unk2C;
    char unk_30[0x24];
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    char unk_60[0x4];
    void * unk64;
    char unk_68[0xC];
    f32 unk74;
    f32 unk78;
    char unk_7C[0xC];
    f32 unk88;
    void * unk8C;
    void * unk90;
    void * unk94;
    s32 unk98;
    s32 unk9C;
    s32 unkA0;
    s32 unkA4;
    s32 unkA8;
    s32 unkAC;
    char unk_B0[0x14];
    s32 unkC4;
    s32 unkC8;
};
f32 func_00200EA8(void *);
f32 func_00200EB8(void *);
float func_00200EC8(void *);
float func_00200ED8(void *);
void func_002E9600(struct mDBox *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    f32 var_f0;

    if (arg0->unkC4 != 0) {
        *arg1 = func_00200EA8(arg0);
        *arg2 = func_00200EB8(arg0);
        *arg3 = func_00200EC8(arg0);
        var_f0 = func_00200ED8(arg0);
    } else {
        *arg1 = func_00200EC8(arg0);
        *arg2 = func_00200ED8(arg0);
        *arg3 = func_00200EA8(arg0);
        var_f0 = func_00200EB8(arg0);
    }
    *arg4 = var_f0;
}
