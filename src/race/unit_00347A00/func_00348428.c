#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

f32 func_00368548(f32, f32);                        /* extern */

struct func_00348428_arg0 {
    char pad0[0x462];
    s8 unk462;
    char pad463[0x25];
    f32 unk488;
    char pad48C[0x88];
    f32 unk514;
    char pad518[0x8];
    u8 unk520;
    char pad521[0x1B];
    f32 unk53C;
};
struct func_00348428_arg1 {
    char pad0[0x8];
    s16 unk8;
    char padA[0x2];
    s16 unkC;
};

void func_00348428(struct func_00348428_arg0 *arg0, struct func_00348428_arg1 *arg1) {
    f32 var_f13;

    if (arg0->unk514 != 0x0.0p+0f) {
        var_f13 = arg0->unk53C;
        if (arg0->unk520 == 0) {
            var_f13 = -var_f13;
        }
        if (var_f13 >= -0x1.1c71c60000000p-2f) {
            arg0->unk488 = func_00368548(arg0->unk488, var_f13);
        }
        if ((arg1->unk8 == 0) && (arg1->unkC == 0) && (arg0->unk53C < -0x1.1c71c60000000p-2f)) {
            arg0->unk462 = 1;
        }
    }
}
