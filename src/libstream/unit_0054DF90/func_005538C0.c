/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

void func_00578908(s32);                         /* extern */

struct func_005538C0_arg0 {
    char pad0[0x5C];
    s32 unk5C;
    s32 unk60;
};

void func_005538C0(struct func_005538C0_arg0 *arg0) {
    func_00578908(arg0->unk5C);
    func_00578908(arg0->unk60);
}
