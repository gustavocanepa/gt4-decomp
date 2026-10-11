#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_006089A0_arg0 {
    char pad0[0xC0];
    s32 unkC0;
};

void func_006089A0(void *arg0, s32 *arg1) {
    s32 *temp_a2;

    temp_a2 = arg0 + (((struct func_006089A0_arg0 *)arg0)->unkC0 * 4);
    if (temp_a2 != NULL) {
        *temp_a2 = *arg1;
    }
    ((struct func_006089A0_arg0 *)arg0)->unkC0 = (s32) (((struct func_006089A0_arg0 *)arg0)->unkC0 + 1);
}
