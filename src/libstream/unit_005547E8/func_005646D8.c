#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_005ADCB0(s32);                         /* extern */

extern char D_0064C4B0[];
struct func_005646D8_arg0 {
    char pad0[0x1C];
    s32 unk1C;
    s32 unk20;
};

void func_005646D8(struct func_005646D8_arg0 *arg0) {
    s32 temp_v0;

    temp_v0 = arg0->unk1C;
    if (temp_v0 != -1) {
        func_005ADCB0(temp_v0);
        arg0->unk1C = -1;
        *(s32 *)D_0064C4B0 = 0;
    }
    func_005ADCB0(arg0->unk20);
}
