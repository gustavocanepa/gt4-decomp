/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_00576788(s32);                         /* extern */
s32 func_005767C0(s32);                         /* extern */
s32 func_005767E0(s32);                         /* extern */

struct func_004AE008_arg0 {
    char pad0[0x3078];
    s32 unk3078;
};

void func_004AE008(void *arg0) {
    s32 temp_s1;
    s32 temp_v0;

    temp_s1 = arg0 + 0x3048;
    func_00576788(temp_s1);
    temp_v0 = ((struct func_004AE008_arg0 *)arg0)->unk3078 + 1;
    ((struct func_004AE008_arg0 *)arg0)->unk3078 = temp_v0;
    if (temp_v0 != 1) {
        func_005767E0(temp_s1);
    }
    func_005767C0(temp_s1);
}
