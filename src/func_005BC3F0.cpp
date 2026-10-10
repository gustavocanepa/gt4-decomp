/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): __gcc_bcmp (libgcc2.c).
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
typedef int s32;
typedef unsigned char u8;

extern "C" s32 func_005BC3F0(const u8 *a, const u8 *b, s32 n) {
    while (n != 0) {
        s32 x = *a++;
        s32 y = *b++;
        if (x != y) return x - y;
        n--;
    }
    return 0;
}
