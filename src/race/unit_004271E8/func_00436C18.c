#include "types.h"
void *memcpy(void *, const void *, unsigned int);

s32 func_00448DC8(s8 *);                            /* extern */

struct func_00436C18_arg0 {
    char pad0[0x115C];
    s32 unk115C;
};

void func_00436C18(struct func_00436C18_arg0 *arg0, s8 *arg1) {
    if (*arg1 == 0) {
        arg0->unk115C = 0;
        return;
    }
    arg0->unk115C = func_00448DC8(arg1);
}
