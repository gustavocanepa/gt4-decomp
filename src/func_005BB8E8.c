/* compiler: ee-gcc2.96-no-strict-aliasing */
/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): __negdi2 (libgcc2.c).
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
/* libgcc2.c __negdi2 with 32-bit words (DWtype is a 64-bit long long). */
typedef int SItype;
typedef unsigned int USItype;
typedef long long DItype;
struct DIstruct { SItype low, high; };
typedef union { struct DIstruct s; DItype ll; } DIunion;

DItype func_005BB8E8(DItype u)
{
    DIunion w;
    DIunion uu;

    uu.ll = u;
    w.s.low = -uu.s.low;
    w.s.high = -uu.s.high - ((USItype) w.s.low > 0);
    return w.ll;
}
