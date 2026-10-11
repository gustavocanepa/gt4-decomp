#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 free(s32);                         /* extern */
s32 func_00578090(void *, s32);             /* extern */
s32 func_005C1628(void *);                      /* extern */

extern char D_00689938[];
struct func_005542D0_arg0 {
    char pad0[0x38];
    s32 unk38;
    s32 unk3C;
};

void func_005542D0(struct func_005542D0_arg0 *arg0, s32 arg1) {
    s32 temp_v1;

    arg0->unk38 = (s32)D_00689938;
    temp_v1 = arg0->unk3C;
    if (temp_v1 != 0) {
        free(temp_v1);
    }
    func_00578090(arg0, 0);
    if (arg1 & 1) {
        func_005C1628(arg0);
    }
}
