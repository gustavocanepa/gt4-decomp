/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): a function of libgcc.a (libgcc2.c, config/fp-bit.c or frame.c), in libgcc.a's code at 0x5ba060-0x5c1ce0.
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
typedef int s32;

struct Rec {
    s32 size;
    s32 a;
    s32 b;
};

extern "C" s32 func_005BEE58(Rec *r) {
    s32 n = 0;
    while (r->size != 0) {
        if (r->a != 0 && r->b != 0)
            n++;
        r = (Rec *)((char *)r + r->size + 4);
    }
    return n;
}
