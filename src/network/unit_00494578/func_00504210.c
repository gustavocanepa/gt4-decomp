#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00503AE0(s32);                         /* extern */
s32 func_00503CC8(s32, void *);                 /* extern */

struct func_00504210_arg0 {
    s32 unk0;
    void *unk4;
};
struct func_00504210_temp_a1 {
    char pad0[0x18];
    s32 unk18;
};

void func_00504210(struct func_00504210_arg0 *arg0) {
    s32 temp_a0;
    struct func_00504210_temp_a1 *temp_a1;

    temp_a0 = arg0->unk0;
    if (temp_a0 != 0) {
        temp_a1 = arg0->unk4;
        if (temp_a1 != NULL) {
            if (temp_a1->unk18 != 0) {
                func_00503CC8(temp_a0, temp_a1);
            }
            arg0->unk4 = NULL;
        }
        func_00503AE0(arg0->unk0);
        arg0->unk0 = 0;
    }
}
