#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00473000(s32, s32, void *, s32, s32); /* extern */
void *func_004A5B70(s32);                       /* extern */

struct func_0047E880_temp_v0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
};
struct func_0047E880_arg1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
};

void func_0047E880(s32 arg0, void *arg1) {
    void *temp_v0;

    temp_v0 = func_004A5B70(2);
    ((struct func_0047E880_temp_v0 *)temp_v0)->unk0 = (f32) ((struct func_0047E880_arg1 *)arg1)->unk0;
    ((struct func_0047E880_temp_v0 *)temp_v0)->unk4 = (f32) ((struct func_0047E880_arg1 *)arg1)->unk4;
    ((struct func_0047E880_temp_v0 *)temp_v0)->unk8 = (f32) ((struct func_0047E880_arg1 *)arg1)->unk8;
    ((struct func_0047E880_temp_v0 *)temp_v0)->unkC = (f32) ((struct func_0047E880_arg1 *)arg1)->unk4;
    ((struct func_0047E880_temp_v0 *)temp_v0)->unk10 = (f32) ((struct func_0047E880_arg1 *)arg1)->unk0;
    ((struct func_0047E880_temp_v0 *)temp_v0)->unk14 = (f32) ((struct func_0047E880_arg1 *)arg1)->unkC;
    ((struct func_0047E880_temp_v0 *)temp_v0)->unk18 = (f32) ((struct func_0047E880_arg1 *)arg1)->unk8;
    ((struct func_0047E880_temp_v0 *)temp_v0)->unk1C = (f32) ((struct func_0047E880_arg1 *)arg1)->unkC;
    func_00473000(arg0, 4, temp_v0, 0, 0);
}
