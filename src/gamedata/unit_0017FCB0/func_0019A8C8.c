#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0019A698();                            /* extern */
s32 func_001CA6F8(void *, s32, s32, void *);    /* extern */

extern char D_0019A630[];
struct func_0019A8C8_arg0 {
    char pad0[0xA0];
    void *unkA0;
    char padA4[0x48];
    s32 unkEC;
};
struct func_0019A8C8_temp_a1 {
    char pad0[0x3C];
    s32 unk3C;
};

s32 func_0019A8C8(struct func_0019A8C8_arg0 *arg0) {
    s32 temp_a3;
    struct func_0019A8C8_temp_a1 *temp_a1;

    func_0019A698();
    temp_a3 = arg0->unkEC;
    if (temp_a3 != 0) {
        temp_a1 = arg0->unkA0;
        if (temp_a1->unk3C == 0) {
            return func_001CA6F8(temp_a1, temp_a3, (s32)D_0019A630, arg0);
        }
    }
    return 0;
}
