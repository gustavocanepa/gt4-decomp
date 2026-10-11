#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_002B8598_arg0 {
    char pad0[0xC4];
    f32 unkC4;
};

void func_002B8598(struct func_002B8598_arg0 *arg0, f32 fparg0) {
    arg0->unkC4 = fparg0;
}
