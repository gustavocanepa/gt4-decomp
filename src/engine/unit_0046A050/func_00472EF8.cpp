#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00473638();                            /* extern */
s32 func_0049C6C8(s32, void *, s32, s32, s32); /* extern */
void *func_004A5B70(s32);                       /* extern */

struct func_00472EF8_arg0 {
    char pad0[0x14];
    s32 unk14;
};
struct func_00472EF8_temp_v0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
};
struct func_00472EF8_arg1 {
    f32 unk0;
    f32 unk4;
};
struct func_00472EF8_arg2 {
    f32 unk0;
    f32 unk4;
};
struct func_00472EF8_arg3 {
    f32 unk0;
    f32 unk4;
};

void func_00472EF8(void *arg0, void *arg1, void *arg2, void *arg3) {
    void *temp_v0;

    if (((struct func_00472EF8_arg0 *)arg0)->unk14 == 0) {
        func_00473638();
    }
    temp_v0 = func_004A5B70(2);
    ((struct func_00472EF8_temp_v0 *)temp_v0)->unk0 = (f32) ((struct func_00472EF8_arg1 *)arg1)->unk0;
    ((struct func_00472EF8_temp_v0 *)temp_v0)->unk4 = (f32) ((struct func_00472EF8_arg1 *)arg1)->unk4;
    ((struct func_00472EF8_temp_v0 *)temp_v0)->unk8 = (f32) ((struct func_00472EF8_arg2 *)arg2)->unk0;
    ((struct func_00472EF8_temp_v0 *)temp_v0)->unkC = (f32) ((struct func_00472EF8_arg2 *)arg2)->unk4;
    ((struct func_00472EF8_temp_v0 *)temp_v0)->unk10 = (f32) ((struct func_00472EF8_arg3 *)arg3)->unk0;
    ((struct func_00472EF8_temp_v0 *)temp_v0)->unk14 = (f32) ((struct func_00472EF8_arg3 *)arg3)->unk4;
    func_0049C6C8(1, temp_v0, 0, 0, 0);
}
