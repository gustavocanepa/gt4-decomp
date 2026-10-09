typedef int s32;

extern void *SparkParticle__vtable;
extern "C" void *func_003C26A8(void *);

extern "C" void *SparkParticle__structor_0(void *arg0) {
    void *r0 = func_003C26A8(arg0);
    if (r0 != 0) {
        *(void **)((char *)r0 + 0x4) = &SparkParticle__vtable;
        *(void **)(r0) = *(void **)((char *)arg0 + 0x4);
        *(void **)((char *)arg0 + 0x4) = r0;
    }
    return r0;
}
