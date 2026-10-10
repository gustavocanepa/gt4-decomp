typedef int s32;
typedef unsigned int u128 __attribute__((mode(TI)));

extern "C" void func_0048EB10(u128 *m, u128 *out, u128 *v) {
    s32 spare[4];
    __asm__ volatile("qmtc2.i %0, $vf1" : : "r"(m[0]));
    __asm__ volatile("qmtc2.ni %0, $vf2" : : "r"(m[1]));
    __asm__ volatile("qmtc2.ni %0, $vf3" : : "r"(m[2]));
    __asm__ volatile("qmtc2.ni %0, $vf4" : : "r"(m[3]));
    __asm__ volatile("qmtc2.ni %0, $vf5" : : "r"(*v));
    __asm__ volatile("vmulax.xyzw ACC, $vf1, $vf5x");
    __asm__ volatile("vmadday.xyzw ACC, $vf2, $vf5y");
    __asm__ volatile("vmaddaz.xyzw ACC, $vf3, $vf5z");
    __asm__ volatile("vmaddw.xyzw $vf5, $vf4, $vf5w");
    u128 r;
    __asm__ volatile("qmfc2.ni %0, $vf5" : "=r"(r));
    *out = r;
    spare[0] = 0;
}
