#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_0054D730();                            /* extern */
s32 func_0054FE78(s32);                         /* extern */
s32 func_005646D8(s32);                         /* extern */
s32 func_005ADAB0(s32);                         /* extern */
s32 func_005ADAF0(s32);                         /* extern */

extern char D_0064C4C4[];
struct func_0054F9A8_arg0 {
    s32 unk0;
    char pad4[0x4];
    s32 unk8;
    s32 unkC;
};

void func_0054F9A8(struct func_0054F9A8_arg0 *arg0) {
    s32 temp_s1;

    func_005646D8(arg0->unkC);
    func_0054FE78(arg0->unk8);
    func_0054D730();
    temp_s1 = arg0->unk0;
    func_005ADAF0(temp_s1);
    func_005ADAB0(temp_s1);
    *(s32 *)D_0064C4C4 = 0;
}
