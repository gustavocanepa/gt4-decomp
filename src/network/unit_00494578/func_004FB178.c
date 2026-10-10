/* compiler: ee-gcc2.96-nsa-nosib */
#include "types.h"
#define NULL 0
void *memcpy(void *, const void *, unsigned int);

struct func_004FB178_arg0 {
    char pad0[0xEE0];
    s32 unkEE0;
};

void func_004FB178(struct func_004FB178_arg0 *arg0, s32 *arg1) {
    s32 *var_a1;
    s32 var_v1;

    var_a1 = arg1;
    var_v1 = 0;
    if (arg0->unkEE0 > 0) {
        do {
            *var_a1 = 0;
            var_v1 += 1;
            var_a1 += 1;
        } while (var_v1 < arg0->unkEE0);
    }
}
