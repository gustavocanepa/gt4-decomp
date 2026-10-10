/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00575950(void *);                      /* extern */
s32 func_00575A38(void *);                      /* extern */
s32 func_00575A40(void *);                      /* extern */
s32 func_00576788();                            /* extern */
s32 func_005767C0(void *);                      /* extern */

struct func_005755C0_arg0 {
    char pad0[0x50];
    s32 unk50;
};

void func_005755C0(struct func_005755C0_arg0 *arg0) {
    func_00576788();
    if (arg0->unk50 != 0) {
        func_00575950(arg0);
        func_00575A38(arg0);
        func_00575A40(arg0);
    }
    func_005767C0(arg0);
}
