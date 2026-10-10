#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void *func_0021A820();                              /* extern */
void *func_0021A850(s32);                           /* extern */
s32 func_004A7844(f32, f32, f32);               /* extern */
s32 func_004A7988(f32);                         /* extern */
s32 func_004A79B0(f32);                         /* extern */
s32 func_004A79D8(f32);                         /* extern */

struct MModel__virtual_03_temp_s1 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};
struct MModel__virtual_03_temp_s0 {
    f32 unk0;
    f32 unk4;
    f32 unk8;
};

void MModel__virtual_03(s32 arg0) {
    void *temp_s0;
    void *temp_s1;

    temp_s1 = func_0021A820();
    temp_s0 = func_0021A850(arg0);
    func_004A7844(((struct MModel__virtual_03_temp_s1 *)temp_s1)->unk0, ((struct MModel__virtual_03_temp_s1 *)temp_s1)->unk4, ((struct MModel__virtual_03_temp_s1 *)temp_s1)->unk8);
    func_004A79D8(((struct MModel__virtual_03_temp_s0 *)temp_s0)->unk8);
    func_004A7988(((struct MModel__virtual_03_temp_s0 *)temp_s0)->unk0);
    func_004A79B0(((struct MModel__virtual_03_temp_s0 *)temp_s0)->unk4);
}
