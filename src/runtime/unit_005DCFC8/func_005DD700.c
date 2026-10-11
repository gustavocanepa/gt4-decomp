#include "types.h"
void *memcpy(void *, const void *, unsigned int);

struct func_005DD700_arg0 {
    char pad0[0xA0];
    f32 unkA0;
};

void func_005DD700(struct func_005DD700_arg0 *arg0, f32 fparg0) {
    arg0->unkA0 = fparg0;
}
