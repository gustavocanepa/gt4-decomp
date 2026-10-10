/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00576788(void *);                      /* extern */
s32 func_005767C0(void *);                      /* extern */
s32 func_0057CC80(s32, void *);                 /* extern */

struct func_004AD438_arg1 {
    char pad0[0x80];
    s32 unk80;
};

void func_004AD438(s32 arg0, void *arg1) {
    void *temp_s2;

    temp_s2 = arg0 + 0x10;
    func_00576788(temp_s2);
    func_00576788(arg1);
    func_0057CC80(arg0 + 0x4C, arg1 + 0x3C);
    ((struct func_004AD438_arg1 *)arg1)->unk80 = 0;
    func_005767C0(arg1);
    func_005767C0(temp_s2);
}
