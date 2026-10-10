#include "gt4/SparkParticle.h"
typedef int s32;

extern void *SparkParticle__vtable;
extern "C" void *func_003C26A8(void *);

struct SparkParticle__structor_0_r0 {
    char pad0[0x4];
    void *unk4;
};

extern "C" void *SparkParticle__structor_0(struct SparkParticle *arg0) {
    void *r0 = func_003C26A8(arg0);
    if (r0 != 0) {
        ((struct SparkParticle__structor_0_r0 *)r0)->unk4 = &SparkParticle__vtable;
        *(void **)(r0) = arg0->unk4;
        arg0->unk4 = r0;
    }
    return r0;
}
