#include "types.h"
#include "gt4/HModuleFrame.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char HModuleFrame__vtable[];
extern char D_0069E278[];
void func_00318E68(void *, void *);
void *func_00326750(s32, s32, void *);
struct HModuleFrame__structor_0_temp_v0 {
    s32 unk0;
    s32 unk4;
};
void HModuleFrame__structor_0(struct HModuleFrame *arg0, s32 arg1) {
    struct HModuleFrame__structor_0_temp_v0 *temp_v0;
    temp_v0 = func_00326750(8, 4, D_0069E278);
    temp_v0->unk4 = (s32) arg0->unk20;
    temp_v0->unk0 = (s32)HModuleFrame__vtable;
    arg0->unk20 = arg1;
    func_00318E68(arg0, temp_v0);
}
