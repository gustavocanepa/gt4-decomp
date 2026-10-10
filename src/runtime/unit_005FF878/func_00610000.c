#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00578480(s32);                         /* extern */
s32 func_00578500(s32);                         /* extern */

extern char D_0064C3C8[];
struct func_00610000_arg0 {
    char pad0[0x3C];
    s32 unk3C;
};

s32 func_00610000(struct func_00610000_arg0 *arg0) {
    s32 temp_s1;

    func_00578500(*(s32 *)(s32)D_0064C3C8);
    temp_s1 = arg0->unk3C;
    func_00578480(*(s32 *)(s32)D_0064C3C8);
    return temp_s1;
}
