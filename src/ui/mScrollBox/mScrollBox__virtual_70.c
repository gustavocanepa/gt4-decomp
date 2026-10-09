typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64;
typedef float f32; typedef double f64;
typedef int s128 __attribute__((mode(TI))); typedef unsigned int u128 __attribute__((mode(TI)));
#define NULL 0
void *memcpy(void *, const void *, unsigned int);
/*
 * This header contains macros emitted by m2c in "valid syntax" mode,
 * which can be enabled by passing `--valid-syntax` on the command line.
 *
 * In this mode, unhandled types and expressions are emitted as macros so
 * that the output is compilable without human intervention.
 */

#ifndef M2C_MACROS_H
#define M2C_MACROS_H

/* Unknown types */
typedef s32 M2C_UNK;
typedef s8  M2C_UNK8;
typedef s16 M2C_UNK16;
typedef s32 M2C_UNK32;
typedef s64 M2C_UNK64;

/* Unknown field access, like `*(type_ptr) &expr->unk_offset` */
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))

/* Bitwise (reinterpret) cast */
#define M2C_BITWISE(type, expr) ((type)(expr))

/* Unaligned reads */
#define M2C_LWL(expr) (expr)
#define M2C_FIRST3BYTES(expr) (expr)
#define M2C_UNALIGNED32(expr) (expr)

/* Unhandled instructions */
#define M2C_ERROR(desc) (0)
#define M2C_TRAP_IF(cond) (0)
#define M2C_BREAK() (0)
#define M2C_SYNC() (0)
#define M2C_DCACHE_CLEAN(addr) (0)
#define M2C_DCACHE_INVALIDATE(addr) (0)
#define M2C_DCACHE_CLEAN_INVALIDATE(addr) (0)
#define M2C_DCACHE_BLOCK_SETZERO(addr) (0)
#define M2C_DCACHE_BLOCK_SETZERO_LOCKED(addr) (0)
#define M2C_ICACHE_INVALIDATE(addr) (0)
#define M2C_PREFETCH(addr) (0)
#define M2C_PREFETCH_STORE(addr) (0)

#define GLUE_F64(a, b) (0.0)
#define MULT_HI(a, b) (0)
#define MULTU_HI(a, b) (0)
#define DMULT_HI(a, b) (0)
#define DMULTU_HI(a, b) (0)
#define CLZ(x) (0)
#define REVERSE_BITS(x) (0)
#define ROTATE_RIGHT(x, shift) (0)
#define ARM_RRX(x, carry) (0)
#define BSWAP32(x) (0)
#define BSWAP16(x) (0)
#define BSWAP16X2(x) (0)

/* Carry/overflow bits from partially-implemented instructions */
#define M2C_CARRY 0
#define M2C_OVERFLOW(a) (0)

/* Memcpy patterns */
#define M2C_MEMCPY_ALIGNED memcpy
#define M2C_MEMCPY_UNALIGNED memcpy
#define M2C_STRUCT_COPY memcpy

/* Sh2 control register loads/stores */
#define M2C_LOAD_SR() (0)
#define M2C_LOAD_GBR() (0)
#define M2C_LOAD_VBR() (0)
#define M2C_STORE_SR(a)
#define M2C_STORE_GBR(a)
#define M2C_STORE_VBR(a)

#define M2C_CMP_STR(a, b) (0)
#define M2C_TAS_B(a) (0)

#endif

f32 func_0025B2B0(void *);                          /* extern */
M2C_UNK func_0025B2E0(s32, f32);                    /* extern */
f32 func_0025B310(void *);                          /* extern */
M2C_UNK func_0025B340(s32, f32);                    /* extern */
f32 func_0025B370(void *);                          /* extern */
M2C_UNK func_0025B3A0(s32, f32);                    /* extern */
f32 func_0025B3D0(void *);                          /* extern */
M2C_UNK func_0025B400(s32, f32);                    /* extern */
void mWidget__virtual_70(void *, M2C_UNK, s32);                     /* extern */
s32 func_00265DC8(void *);                          /* extern */
M2C_UNK func_00265FF0(s32, s32);                    /* extern */

typedef struct VEntry { s16 delta; s16 index; void *fn; } VEntry;
#define VENT(obj, off) ((VEntry *)(*(char **)((char *)(obj) + 4) + (off)))
#define VCALL(T, obj, off) ({ VEntry *e_ = VENT(obj, off); ((T (*)(void *))e_->fn)((char *)(obj) + e_->delta); })
void mScrollBox__virtual_70(void *arg0, M2C_UNK arg1, s32 arg2) {
    f32 temp_f12;
    f32 temp_f20;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f20;
    f32 var_f21;
    s32 temp_s0;
    void *temp_a0;
    void *temp_a1;
    void *temp_a1_2;
    void *temp_a1_3;
    void *temp_a1_4;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v1;
    void *temp_v1_2;

    mWidget__virtual_70(arg0, arg1, 0);
    if (arg2 == 0) {
        return;
    }
    if (func_00265DC8(arg0) == 0) {
        return;
    }
    temp_a1 = M2C_FIELD(arg0, void **, 0xB0);
    if (temp_a1 == NULL) {
        return;
    }
    if (M2C_FIELD(arg0, s32 *, 0xB8) != 0) {
        temp_v1 = M2C_FIELD(temp_a1, void **, 4);
        func_00265FF0(M2C_FIELD(arg0, s32 *, 0xB8), VCALL(s32, temp_a1, 0x350));
    }
    if (M2C_FIELD(arg0, s32 *, 0xBC) != 0) {
        temp_a1_2 = M2C_FIELD(arg0, void **, 0xB0);
        temp_v1_2 = M2C_FIELD(temp_a1_2, void **, 4);
        func_00265FF0(M2C_FIELD(arg0, s32 *, 0xBC), VCALL(s32, temp_a1_2, 0x358));
    }
    if (M2C_FIELD(arg0, s32 *, 0xB4) != 0) {
        var_f21 = VCALL(f32, M2C_FIELD(arg0, void **, 0xB0), 0x340);
        var_f20 = VCALL(f32, M2C_FIELD(arg0, void **, 0xB0), 0x348);
        if (var_f21 < 0.0f) {
            var_f21 = 0.0f;
        }
        if (var_f20 > 1.0f) {
            var_f20 = 1.0f;
        }
        temp_a0 = M2C_FIELD(arg0, void **, 0xB0);
        temp_s0 = M2C_FIELD(temp_a0, s32 *, 0xB0);
        if (temp_s0 == 1) {
            var_f0 = func_0025B310(temp_a0);
        } else {
            var_f0 = func_0025B2B0(temp_a0);
        }
        if (temp_s0 == 1) {
            var_f0_2 = func_0025B3D0(M2C_FIELD(arg0, void **, 0xB0));
        } else {
            var_f0_2 = func_0025B370(M2C_FIELD(arg0, void **, 0xB0));
        }
        temp_f20 = var_f20 * var_f0_2;
        temp_f12 = var_f0 + (var_f21 * var_f0_2);
        switch (temp_s0) {                          /* irregular */
        case 1:
            func_0025B340(M2C_FIELD(arg0, s32 *, 0xB4), temp_f12);
            func_0025B400(M2C_FIELD(arg0, s32 *, 0xB4), temp_f20);
            return;
        case 0:
            func_0025B2E0(M2C_FIELD(arg0, s32 *, 0xB4), temp_f12);
            func_0025B3A0(M2C_FIELD(arg0, s32 *, 0xB4), temp_f20);
            return;
        }
    }
}
