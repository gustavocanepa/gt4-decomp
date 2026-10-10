/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

s32 func_004AD808();                            /* extern */
s32 func_005788B8(s32);                         /* extern */

struct func_004AD890_arg0 {
    char pad0[0x94];
    s32 unk94;
};

void func_004AD890(struct func_004AD890_arg0 *arg0) {
    func_004AD808();
    func_005788B8(arg0->unk94);
}
