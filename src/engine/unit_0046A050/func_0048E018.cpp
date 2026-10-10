typedef int s32;
typedef unsigned int u128 __attribute__((mode(TI)));

extern "C" void func_0048E018(u128 *dst, s32 i, u128 *a, u128 *b) {
    s32 spare[4];
    a += i;
    __asm__ volatile("qmtc2.i %0, $vf1" : : "r"(*a));
    b += i;
    __asm__ volatile("qmtc2.ni %0, $vf2" : : "r"(*b));
    __asm__ volatile("vmul.xyzw $vf1, $vf1, $vf2");
    u128 r;
    __asm__ volatile("qmfc2.ni %0, $vf1" : "=r"(r));
    dst += i;
    *dst = r;
    spare[0] = i;
}
