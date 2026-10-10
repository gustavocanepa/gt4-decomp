#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern "C" {
s32 RaceBase__getRaceModeKeyString(s32);                             /* extern */
s32 DisplayRText__getRTextStr(s32);                             /* extern */
s32 func_0057DA20(void *, s32, s32, s32);   /* extern */

extern char D_006A3830[];
struct func_003E0940_arg0 {
    char pad0[0x540];
    s32 unk540;
};

void func_003E0940(char *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_v0;
    s32 temp_v0_2;

    ((struct func_003E0940_arg0 *)arg0)->unk540 = arg3;
    temp_v0 = RaceBase__getRaceModeKeyString(arg1);
    temp_v0_2 = DisplayRText__getRTextStr(temp_v0);
    func_0057DA20(arg0 + 0x500, (s32)D_006A3830, (temp_v0_2 != 0) ? temp_v0_2 : temp_v0, arg2);
}

}
