/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

s32 func_004EB770(void *);                          /* extern */
s32 func_004EB798(void *);                      /* extern */
s32 func_004EB890(void *);                          /* extern */

struct func_004EB7D0_arg0 {
    char pad0[0x48];
    s32 unk48;
    char pad4C[0x9C];
    s32 unkE8;
};

void func_004EB7D0(struct func_004EB7D0_arg0 *arg0) {
loop_1:
    if (func_004EB890(arg0) != 0) {
        if (func_004EB770(arg0) == 0) {
            goto loop_1;
        }
    }
    if (arg0->unkE8 >= 0x190) {
        arg0->unk48 = -1;
    }
    func_004EB798(arg0);
}
