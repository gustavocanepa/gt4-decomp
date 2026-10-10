#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern "C" {
s32 func_003310E0(s32);                         /* extern */
s32 func_00331520(s32, s32, s32);               /* extern */

struct func_003355F0_arg0 {
    char pad0[0xC];
    s32 unkC;
    s32 unk10;
};

void func_003355F0(char *arg0) {
    s32 temp_s1;

    temp_s1 = (s32)(arg0 + 0x1C);
    func_003310E0(temp_s1);
    func_00331520(temp_s1, ((struct func_003355F0_arg0 *)arg0)->unkC, ((struct func_003355F0_arg0 *)arg0)->unk10);
}

}
