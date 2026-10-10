#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00600B78_arg0 {
    char pad0[0xB6C0];
    s32 unkB6C0;
};

s32 func_00600B78(struct func_00600B78_arg0 *arg0) {
    return arg0->unkB6C0;
}
