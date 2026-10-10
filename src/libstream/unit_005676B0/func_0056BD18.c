#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

s32 func_00567D08(s32);                         /* extern */
s32 func_00567F10(void *);                      /* extern */

struct func_0056BD18_arg0 {
    char pad0[0x4];
    s32 unk4;
};

void func_0056BD18(struct func_0056BD18_arg0 *arg0) {
    func_00567D08(arg0->unk4);
    func_00567F10(arg0);
}
