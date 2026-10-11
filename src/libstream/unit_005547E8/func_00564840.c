#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_005ADCC0(s32);                         /* extern */
s32 func_005ADCE0(s32);                         /* extern */

struct func_00564840_arg0 {
    char pad0[0x18];
    s32 unk18;
    char pad1C[0x4];
    s32 unk20;
};

s32 func_00564840(struct func_00564840_arg0 *arg0) {
    s32 temp_s1;

    func_005ADCE0(arg0->unk20);
    temp_s1 = arg0->unk18 == 0;
    func_005ADCC0(arg0->unk20);
    return temp_s1;
}
