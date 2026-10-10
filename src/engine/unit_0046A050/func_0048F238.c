#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0048F238_arg0 {
    char pad0[0xC];
    s32 unkC;
};

void func_0048F238(struct func_0048F238_arg0 *arg0) {
    s32 var_v0;

    var_v0 = arg0->unkC;
    if (var_v0 > 0) {
        do {
            var_v0 -= 1;
        } while (var_v0 != 0);
    }
}
