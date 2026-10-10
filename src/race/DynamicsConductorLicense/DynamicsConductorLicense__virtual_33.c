#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00357800(s32, void *);                 /* extern */
s32 func_00357830(s32, void *);                 /* extern */
s32 func_0035E3F0(void *);                      /* extern */
s32 func_003F60E8(s32);                             /* extern */

struct DynamicsConductorLicense__virtual_33_arg1 {
    char pad0[0x5B6];
    u8 unk5B6;
};

void DynamicsConductorLicense__virtual_33(s32 arg0, struct DynamicsConductorLicense__virtual_33_arg1 *arg1) {
    if (arg1->unk5B6 != 0) {
        func_0035E3F0(arg1);
        return;
    }
    if (func_003F60E8(arg0 + 0xF818) == 0) {
        func_00357800(arg0, arg1);
        return;
    }
    func_00357830(arg0, arg1);
}
