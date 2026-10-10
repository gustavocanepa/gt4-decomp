/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): __fixunssfsi (config/fp-bit.c float_to_usi).
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
/* NO_NANS build: the NaN and infinity tests compile away */
typedef float FLO_type;
typedef unsigned int fractype;
typedef unsigned int USItype;

#define MAX_USI_INT ((USItype) ~0)

typedef enum {
    CLASS_SNAN,
    CLASS_QNAN,
    CLASS_ZERO,
    CLASS_NUMBER,
    CLASS_INFINITY
} fp_class_type;

typedef struct {
    fp_class_type class;
    unsigned int sign;
    int normal_exp;
    union {
        fractype ll;
    } fraction;
} fp_number_type;

typedef union {
    FLO_type value;
    fractype value_raw;
} FLO_union_type;

extern void func_005BD9B8(FLO_union_type *src, fp_number_type *dst); /* unpack_d */

static __inline__ int iszero(fp_number_type *x) { return x->class == CLASS_ZERO; }

USItype func_005BE1D0(FLO_type arg_a) {
    fp_number_type a;
    FLO_union_type au;

    au.value = arg_a;
    func_005BD9B8(&au, &a);

    if (iszero(&a))
        return 0;
    /* it is a negative number */
    if (a.sign)
        return 0;
    /* it is a number, but a small one */
    if (a.normal_exp < 0)
        return 0;
    if (a.normal_exp > 31)
        return MAX_USI_INT;
    else if (a.normal_exp > (23 + 7))
        return a.fraction.ll << (a.normal_exp - (23 + 7));
    else
        return a.fraction.ll >> ((23 + 7) - a.normal_exp);
}
