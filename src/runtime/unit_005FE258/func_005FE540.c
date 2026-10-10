#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005FE540_arg0 {
    char pad0[0xF0F4];
    f32 unkF0F4;
};

void func_005FE540(struct func_005FE540_arg0 *arg0, f32 fparg0) {
    arg0->unkF0F4 = fparg0;
}
