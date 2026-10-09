typedef int s32;

extern void *D_00620000;
extern void *ParticleManager__vtable;
extern "C" void *func_003C1310(void *);
extern "C" void *exception__structor_0(s32);
extern "C" void func_003C2070(void *);
extern "C" void func_0040AB98(void *, s32, float, float, float);

extern "C" void ParticleManager__structor_0(void *arg0) {
    *(void **)((char *)arg0 + 0x3ac) = &ParticleManager__vtable;
    void *r0 = func_003C1310(arg0);
    void *r1 = exception__structor_0(((s32)r0 << (s32)0x7));
    *(void **)(arg0) = r1;
    *(void **)((char *)&D_00620000 + 0x1b44) = 0x0;
    func_003C2070(arg0);
    func_0040AB98((char *)arg0 + 0xc, 0x1, 0.000999999960186f, 0.11999999918f, 0.11999999918f);
    func_0040AB98((char *)arg0 + 0x80, 0x2, 0.000999999960186f, 0.129999998957f, 0.129999998957f);
    func_0040AB98((char *)arg0 + 0xf4, 0x3, 0.000999999960186f, 0.13999998942f, 0.13999998942f);
    func_0040AB98((char *)arg0 + 0x168, 0x4, 0.000999999960186f, 0.0999999959022f, 0.0999999959022f);
    func_0040AB98((char *)arg0 + 0x1dc, 0x5, 0.000999999960186f, 0.0999999959022f, 0.0999999959022f);
    func_0040AB98((char *)arg0 + 0x250, 0x6, 0.000999999960186f, 0.0999999959022f, 0.0999999959022f);
    func_0040AB98((char *)arg0 + 0x2c4, 0x7, 0.000999999960186f, 0.0999999959022f, 0.0999999959022f);
    return func_0040AB98((char *)arg0 + 0x338, 0x8, 0.000999999960186f, 0.0999999959022f, 0.0999999959022f);
}
