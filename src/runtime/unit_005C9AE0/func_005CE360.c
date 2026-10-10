#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005CE360_arg0 {
    char pad0[0xAC];
    s32 unkAC;
};

s32 func_005CE360(struct func_005CE360_arg0 *arg0) {
    return arg0->unkAC == 2;
}
