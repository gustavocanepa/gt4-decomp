#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

void func_00251CE8();                            /* extern */

struct func_00213B68_arg0 {
    char pad0[0xE4];
    s32 unkE4;
};

void func_00213B68(struct func_00213B68_arg0 *arg0) {
    func_00251CE8();
    arg0->unkE4 = 1;
}
