#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_0060EFA8_arg0 {
    char pad0[0xFCC];
    s32 unkFCC;
};

s32 func_0060EFA8(struct func_0060EFA8_arg0 *arg0) {
    return arg0->unkFCC == 1;
}
