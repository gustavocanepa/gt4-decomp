#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

extern "C" {
s32 func_00576100(s32);                         /* extern */
s32 func_00576140(s32);                         /* extern */

struct func_0011FF38_arg0 {
    char pad0[0x84];
    s32 unk84;
    s32 unk88;
};

void func_0011FF38(char *arg0, s32 arg1, s32 arg2) {
    s32 temp_s1;

    temp_s1 = (s32)(arg0 + 0x10);
    func_00576100(temp_s1);
    ((struct func_0011FF38_arg0 *)arg0)->unk84 = arg1;
    ((struct func_0011FF38_arg0 *)arg0)->unk88 = arg2;
    func_00576140(temp_s1);
}

}
