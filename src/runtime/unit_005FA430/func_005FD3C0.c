#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_005FD3C0_arg0 {
    char pad0[0x80];
    s32 unk80;
};

void func_005FD3C0(void *arg0, s32 *arg1) {
    s32 *temp_a2;

    temp_a2 = arg0 + (((struct func_005FD3C0_arg0 *)arg0)->unk80 * 4);
    if (temp_a2 != NULL) {
        *temp_a2 = *arg1;
    }
    ((struct func_005FD3C0_arg0 *)arg0)->unk80 = (s32) (((struct func_005FD3C0_arg0 *)arg0)->unk80 + 1);
}
