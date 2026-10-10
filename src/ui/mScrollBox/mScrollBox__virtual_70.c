#include "types.h"
#include "gt4/mScrollBox.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

f32 func_0025B2B0(void *);                          /* extern */
s32 func_0025B2E0(s32, f32);                    /* extern */
f32 func_0025B310(void *);                          /* extern */
s32 func_0025B340(s32, f32);                    /* extern */
f32 func_0025B370(void *);                          /* extern */
s32 func_0025B3A0(s32, f32);                    /* extern */
f32 func_0025B3D0(void *);                          /* extern */
s32 func_0025B400(s32, f32);                    /* extern */
void mWidget__virtual_70(void *, s32, s32);                     /* extern */
s32 func_00265DC8(void *);                          /* extern */
s32 func_00265FF0(s32, s32);                    /* extern */

typedef struct VEntry { s16 delta; s16 index; void *fn; } VEntry;
#define VENT(obj, off) ((VEntry *)(*(char **)((char *)(obj) + 4) + (off)))
#define VCALL(T, obj, off) ({ VEntry *e_ = VENT(obj, off); ((T (*)(void *))e_->fn)((char *)(obj) + e_->delta); })
struct mScrollBox__virtual_70_temp_a1 {
    char pad0[0x4];
    void *unk4;
};
struct mScrollBox__virtual_70_temp_a1_2 {
    char pad0[0x4];
    void *unk4;
};
struct mScrollBox__virtual_70_temp_a0 {
    char pad0[0xB0];
    s32 unkB0;
};

void mScrollBox__virtual_70(struct mScrollBox *arg0, s32 arg1, s32 arg2) {
    f32 temp_f12;
    f32 temp_f20;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f20;
    f32 var_f21;
    s32 temp_s0;
    struct mScrollBox__virtual_70_temp_a0 *temp_a0;
    struct mScrollBox__virtual_70_temp_a1 *temp_a1;
    struct mScrollBox__virtual_70_temp_a1_2 *temp_a1_2;
    void *temp_a1_3;
    void *temp_a1_4;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v1;
    void *temp_v1_2;

    mWidget__virtual_70(arg0, arg1, 0);
    if (arg2 == 0) {
        return;
    }
    if (func_00265DC8(arg0) == 0) {
        return;
    }
    temp_a1 = arg0->unkB0;
    if (temp_a1 == NULL) {
        return;
    }
    if (arg0->unkB8 != 0) {
        temp_v1 = temp_a1->unk4;
        func_00265FF0(arg0->unkB8, VCALL(s32, temp_a1, 0x350));
    }
    if (arg0->unkBC != 0) {
        temp_a1_2 = arg0->unkB0;
        temp_v1_2 = temp_a1_2->unk4;
        func_00265FF0(arg0->unkBC, VCALL(s32, temp_a1_2, 0x358));
    }
    if (arg0->unkB4 != 0) {
        var_f21 = VCALL(f32, arg0->unkB0, 0x340);
        var_f20 = VCALL(f32, arg0->unkB0, 0x348);
        if (var_f21 < 0.0f) {
            var_f21 = 0.0f;
        }
        if (var_f20 > 1.0f) {
            var_f20 = 1.0f;
        }
        temp_a0 = arg0->unkB0;
        temp_s0 = temp_a0->unkB0;
        if (temp_s0 == 1) {
            var_f0 = func_0025B310(temp_a0);
        } else {
            var_f0 = func_0025B2B0(temp_a0);
        }
        if (temp_s0 == 1) {
            var_f0_2 = func_0025B3D0(arg0->unkB0);
        } else {
            var_f0_2 = func_0025B370(arg0->unkB0);
        }
        temp_f20 = var_f20 * var_f0_2;
        temp_f12 = var_f0 + (var_f21 * var_f0_2);
        switch (temp_s0) {                          /* irregular */
        case 1:
            func_0025B340(arg0->unkB4, temp_f12);
            func_0025B400(arg0->unkB4, temp_f20);
            return;
        case 0:
            func_0025B2E0(arg0->unkB4, temp_f12);
            func_0025B3A0(arg0->unkB4, temp_f20);
            return;
        }
    }
}
