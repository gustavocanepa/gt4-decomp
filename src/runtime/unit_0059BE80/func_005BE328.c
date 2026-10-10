/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): unpack_d (config/fp-bit.c, double).
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
/* NO_DENORMALS build; the retail copy also gives infinities an exponent and an implicit one */
typedef double FLO_type;
typedef unsigned long fractype;

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

#define FRACBITS 52
#define EXPBITS 11
#define EXPBIAS 1023
#define EXPMAX 0x7ff
#define NGARDS 8
#define IMPLICIT_1 ((fractype)1 << (FRACBITS + NGARDS))
#define QUIET_NAN ((fractype)1 << (FRACBITS - 1))

void func_005BE328(FLO_union_type *src, fp_number_type *dst) {
    fractype fraction;
    int exp;
    int sign;

    fraction = src->value_raw & ((((fractype)1) << FRACBITS) - (fractype)1);
    exp = ((int)(src->value_raw >> FRACBITS)) & ((1 << EXPBITS) - 1);
    sign = ((int)(src->value_raw >> (FRACBITS + EXPBITS))) & 1;

    dst->sign = sign;
    if (exp == 0) {
        /* tastes like zero */
        dst->class = CLASS_ZERO;
    } else if (exp == EXPMAX) {
        /* Huge exponent */
        dst->normal_exp = EXPBIAS;
        if (fraction == 0) {
            /* Attached to a zero fraction - means infinity */
            dst->class = CLASS_INFINITY;
            dst->fraction.ll = IMPLICIT_1;
        } else {
            /* Non zero fraction, means nan */
            if (fraction & QUIET_NAN)
                dst->class = CLASS_QNAN;
            else
                dst->class = CLASS_SNAN;
            /* Keep the fraction part as the nan number */
            dst->fraction.ll = fraction;
        }
    } else {
        /* Nothing strange about this number */
        dst->normal_exp = exp - EXPBIAS;
        dst->class = CLASS_NUMBER;
        dst->fraction.ll = (fraction << NGARDS) | IMPLICIT_1;
    }
}
