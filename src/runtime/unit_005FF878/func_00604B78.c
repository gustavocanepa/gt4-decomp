#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_00604B78_arg0 {
    char pad0[0x50];
    f32 unk50;
};

void func_00604B78(struct func_00604B78_arg0 *arg0, f32 fparg0) {
    arg0->unk50 = fparg0;
}
