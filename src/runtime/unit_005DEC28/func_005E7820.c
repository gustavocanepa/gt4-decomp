#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005E7820_arg0 {
    char pad0[0xCC];
    f32 unkCC;
};

f32 func_005E7820(struct func_005E7820_arg0 *arg0) {
    return arg0->unkCC;
}
