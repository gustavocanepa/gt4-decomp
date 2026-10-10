/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): a function of libgcc.a (libgcc2.c, config/fp-bit.c or frame.c), in libgcc.a's code at 0x5ba060-0x5c1ce0.
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
typedef float f32;

struct Num {
    int w[4];
};

extern "C" void func_005BD9B8(const f32 *v, Num *out);
extern "C" void func_005BDF58(Num *a, Num *b);

extern "C" void func_005BE020(f32 a, f32 b) {
    Num na;
    Num nb;
    f32 v[2];
    v[0] = a;
    v[1] = b;
    func_005BD9B8(&v[0], &na);
    func_005BD9B8(&v[1], &nb);
    func_005BDF58(&na, &nb);
}
