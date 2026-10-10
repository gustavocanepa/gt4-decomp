/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): __fixsfsi (config/fp-bit.c float_to_si).
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
/* NO_NANS build: only the zero, small and overflow cases are tested */
typedef float FLO_type;
typedef unsigned int fractype;
typedef int SItype;

#define MAX_SI_INT ((SItype) 0x7fffffff)

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

SItype func_005BE120(FLO_type arg_a) {
    fp_number_type a;
    SItype tmp;
    FLO_union_type au;

    au.value = arg_a;
    func_005BD9B8(&au, &a);

    if (iszero(&a))
        return 0;
    /* it is a number, but a small one */
    if (a.normal_exp < 0)
        return 0;
    if (a.normal_exp > 30)
        return a.sign ? (-MAX_SI_INT) - 1 : MAX_SI_INT;
    tmp = a.fraction.ll >> ((23 + 7) - a.normal_exp);
    return a.sign ? (-tmp) : (tmp);
}
