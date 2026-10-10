typedef int s32;
typedef unsigned int u128 __attribute__((mode(TI)));

struct M4 { u128 r[4]; };
extern "C" void func_0048EA48(M4 *, M4 *, s32);

extern "C" void func_0048EA00(M4 *src, s32 a) {
    M4 t;
    t.r[0] = src->r[0];
    t.r[1] = src->r[1];
    t.r[2] = src->r[2];
    t.r[3] = src->r[3];
    func_0048EA48(src, &t, a);
}
