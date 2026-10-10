typedef int s32;
typedef unsigned int u128 __attribute__((mode(TI)));

/* out[i] = a[i] - b[i] on VU0 (libvu0-style inline asm). The original reserves an unused
   16-byte stack slot; a vector local handed to the asm as a memory operand reproduces it. */
extern "C" void func_0048D6C0(u128 *out, s32 i, u128 *a, u128 *b) {
    u128 r;
    u128 t[1];
    a += i;
    __asm__ __volatile__("qmtc2.i %0, $vf1" : : "r"(*a));
    b += i;
    __asm__ __volatile__("qmtc2.ni %0, $vf2" : : "r"(*b));
    __asm__ __volatile__("vsub.xyzw $vf1, $vf1, $vf2" : : "m"(t[0]));
    __asm__ __volatile__("qmfc2.ni %0, $vf1" : "=r"(r));
    out += i;
    *out = r;
}
