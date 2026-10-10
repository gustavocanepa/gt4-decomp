/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): unpack_f (config/fp-bit.c unpack_d, FLOAT).
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
typedef float FLO_type;
typedef unsigned int fractype;
typedef int SItype;

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

/* NO_DENORMALS and NO_NANS: a zero exponent is zero, everything else a number */
void func_005BD9B8(FLO_union_type *src, fp_number_type *dst) {
    fractype fraction;
    int exp;
    int sign;

    fraction = src->value_raw & ((((fractype)1) << 23) - (fractype)1);
    exp = ((int)(src->value_raw >> 23)) & ((1 << 8) - 1);
    sign = ((int)(src->value_raw >> (23 + 8))) & 1;

    dst->sign = sign;
    if (exp == 0) {
        /* tastes like zero */
        dst->class = CLASS_ZERO;
    } else {
        /* Nothing strange about this number */
        dst->normal_exp = exp - 127;
        dst->class = CLASS_NUMBER;
        dst->fraction.ll = (fraction << 7) | (1 << 30);
    }
}
