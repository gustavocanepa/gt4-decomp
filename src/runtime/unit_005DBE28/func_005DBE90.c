#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005DBE90_arg0 {
    char pad0[0xD4];
    f32 unkD4;
};

void func_005DBE90(struct func_005DBE90_arg0 *arg0, f32 fparg0) {
    arg0->unkD4 = fparg0;
}
