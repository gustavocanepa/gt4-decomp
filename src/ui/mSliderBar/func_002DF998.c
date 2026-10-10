#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_0057CE40(s32);                         /* extern */

struct func_002DF998_arg0 {
    char pad0[0xF4];
    f32 unkF4;
};

void func_002DF998(void *arg0, s32 arg1) {
    func_0057CE40(arg0 + 0xCC);
    ((struct func_002DF998_arg0 *)arg0)->unkF4 = (f32) arg1;
}
