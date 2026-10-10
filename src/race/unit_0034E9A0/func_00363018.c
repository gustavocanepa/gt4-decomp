#include "types.h"
void *memcpy(void *, const void *, unsigned int);

void *func_00359510(s32);                           /* extern */

struct func_00363018_temp_v0 {
    char pad0[0x1];
    u8 unk1;
};

struct func_00363018_arg0 {
    char pad0[0x10];
    s32 unk10;
};
struct func_00363018_var_a0 {
    char pad0[0x24];
    s32 unk24;
    char pad28[0x10];
    s32 unk38;
    char pad3C[0x4];
    s32 unk40;
    char pad44[0x14];
    s32 unk58;
    s32 unk5C;
    char pad60[0x30];
    s32 unk90;
    char pad94[0x4];
    s32 unk98;
    s32 unk9C;
    s32 unkA0;
    char padA4[0xE];
    s8 unkB2;
    char padB3[0x1];
    s32 unkB4;
    f32 unkB8;
    s32 unkBC;
    s32 unkC0;
    s32 unkC4;
    char padC8[0x4];
    s32 unkCC;
    s32 unkD0;
    s32 unkD4;
};

void func_00363018(void *arg0) {
    s32 var_a1;
    struct func_00363018_temp_v0 *temp_v0;
    void *var_a0;

    temp_v0 = func_00359510(((struct func_00363018_arg0 *)arg0)->unk10);
    var_a1 = 0;
    if (temp_v0->unk1 != 0) {
        var_a0 = arg0 + 0x164;
        do {
            ((struct func_00363018_var_a0 *)var_a0)->unkBC = 0;
            var_a1 += 1;
            ((struct func_00363018_var_a0 *)var_a0)->unkB2 = -1;
            ((struct func_00363018_var_a0 *)var_a0)->unkB4 = 0;
            ((struct func_00363018_var_a0 *)var_a0)->unkB8 = 1.0f;
            ((struct func_00363018_var_a0 *)var_a0)->unk24 = 0;
            ((struct func_00363018_var_a0 *)var_a0)->unk40 = 0;
            ((struct func_00363018_var_a0 *)var_a0)->unk38 = 0;
            ((struct func_00363018_var_a0 *)var_a0)->unk58 = 0;
            ((struct func_00363018_var_a0 *)var_a0)->unk90 = 0;
            ((struct func_00363018_var_a0 *)var_a0)->unk98 = 0;
            ((struct func_00363018_var_a0 *)var_a0)->unk9C = 0;
            ((struct func_00363018_var_a0 *)var_a0)->unkA0 = 0;
            ((struct func_00363018_var_a0 *)var_a0)->unkC0 = 0;
            ((struct func_00363018_var_a0 *)var_a0)->unkC4 = 0;
            ((struct func_00363018_var_a0 *)var_a0)->unk5C = 0;
            ((struct func_00363018_var_a0 *)var_a0)->unkCC = 0;
            ((struct func_00363018_var_a0 *)var_a0)->unkD0 = 0;
            ((struct func_00363018_var_a0 *)var_a0)->unkD4 = 0;
            var_a0 += 0xEC;
        } while (var_a1 < (s32) temp_v0->unk1);
    }
}
