/* compiler: ee-gcc2.96-no-strict-aliasing */
/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): __ucmpdi2 (libgcc2.c).
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
/* libgcc2.c __ucmpdi2 with 32-bit words (DWtype is a 64-bit long long). */
typedef int SItype;
typedef unsigned int USItype;
typedef long long DItype;
struct DIstruct { SItype low, high; };
typedef union { struct DIstruct s; DItype ll; } DIunion;

int func_005BC2F8(DItype a, DItype b)
{
    DIunion au, bu;

    au.ll = a, bu.ll = b;
    if ((USItype) au.s.high < (USItype) bu.s.high)
        return 0;
    else if ((USItype) au.s.high > (USItype) bu.s.high)
        return 2;
    if ((USItype) au.s.low < (USItype) bu.s.low)
        return 0;
    else if ((USItype) au.s.low > (USItype) bu.s.low)
        return 2;
    return 1;
}
