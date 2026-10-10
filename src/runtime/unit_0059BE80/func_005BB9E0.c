/* compiler: ee-gcc2.96-no-strict-aliasing */
/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): __ashldi3 (libgcc2.c).
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
/* libgcc2.c __ashldi3 with 32-bit words (DWtype is a 64-bit long long, word_type 64-bit). */
typedef int SItype;
typedef unsigned int USItype;
typedef long long DItype;
typedef int word_type __attribute__ ((mode (__word__)));
struct DIstruct { SItype low, high; };
typedef union { struct DIstruct s; DItype ll; } DIunion;

DItype func_005BB9E0(DItype u, word_type b)
{
    DIunion w;
    word_type bm;
    DIunion uu;

    if (b == 0)
        return u;

    uu.ll = u;

    bm = (sizeof (SItype) * 8) - b;
    if (bm <= 0)
    {
        w.s.low = 0;
        w.s.high = (USItype) uu.s.low << -bm;
    }
    else
    {
        USItype carries = (USItype) uu.s.low >> bm;

        w.s.low = (USItype) uu.s.low << b;
        w.s.high = ((USItype) uu.s.high << b) | carries;
    }

    return w.ll;
}
