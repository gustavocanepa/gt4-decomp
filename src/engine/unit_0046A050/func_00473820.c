#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_00490290(s32);
extern s32 PDISTD__global_font_manager;
struct func_00473820_arg0 {
    char pad0[0x28];
    f32 unk28;
};

void func_00473820(struct func_00473820_arg0 *arg0, s32 arg1, f32 fparg0) {
    if (arg1 != 0) {
        func_00490290(PDISTD__global_font_manager);
    }
    arg0->unk28 = fparg0;
}
