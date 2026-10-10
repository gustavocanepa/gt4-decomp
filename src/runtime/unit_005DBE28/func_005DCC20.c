#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005DCC20_arg0 {
    char pad0[0xCC];
    f32 unkCC;
};

void func_005DCC20(struct func_005DCC20_arg0 *arg0, f32 fparg0) {
    arg0->unkCC = fparg0;
}
