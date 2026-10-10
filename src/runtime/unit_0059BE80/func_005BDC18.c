/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): __addsf3 (config/fp-bit.c).
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
/* libgcc fp-bit.c __addsf3 (single precision): unpack both operands, _fpadd_parts, pack */
typedef float FLO_type;
typedef unsigned int fractype;

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
extern fp_number_type *func_005BDA18(fp_number_type *a, fp_number_type *b, fp_number_type *tmp); /* _fpadd_parts */
extern FLO_type func_005BD900(fp_number_type *src); /* pack_d */

FLO_type func_005BDC18(FLO_type arg_a, FLO_type arg_b) {
    fp_number_type a;
    fp_number_type b;
    fp_number_type tmp;
    fp_number_type *res;
    FLO_union_type au, bu;

    au.value = arg_a;
    bu.value = arg_b;

    func_005BD9B8(&au, &a);
    func_005BD9B8(&bu, &b);

    res = func_005BDA18(&a, &b, &tmp);

    return func_005BD900(res);
}
