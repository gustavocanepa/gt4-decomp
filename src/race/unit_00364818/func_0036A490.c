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

void *func_00359510(s32, s32);                      /* extern */
M2C_UNK func_0036A080(void *, s32, void *, f32);    /* extern */
s8 func_0036A1D8(void *, M2C_UNK);                  /* extern */

void func_0036A490(void *arg0) {
    s8 *var_a0;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f3;
    s32 var_a1;
    s32 var_a1_2;
    void *temp_s0;
    void *temp_v0;
    void *var_v0;
    void *var_v1;

    var_a1 = 2;
    temp_s0 = arg0 + 0x104;
    var_v0 = arg0 + 0x128;
    M2C_FIELD(temp_s0, f32 *, 0x5B4) = 0.0f;
    do {
        temp_f0 = M2C_FIELD(var_v0, f32 *, 0x30);
        var_a1 -= 1;
        temp_f2 = M2C_FIELD(var_v0, f32 *, 0);
        var_v0 += 4;
        M2C_FIELD(temp_s0, f32 *, 0x5B4) = (f32) (M2C_FIELD(temp_s0, f32 *, 0x5B4) + (temp_f0 * temp_f2));
    } while (var_a1 >= 0);
    temp_v0 = func_00359510(M2C_FIELD(arg0, s32 *, 0x10), var_a1);
    var_a1_2 = 0;
    if (M2C_FIELD(temp_v0, u8 *, 1) != 0) {
        var_a0 = arg0 + 0x22C;
        var_v1 = arg0 + 0x7B8;
        do {
            var_a1_2 += 1;
            temp_f0_2 = M2C_FIELD(var_v1, f32 *, 0x1C) * M2C_FIELD(temp_s0, f32 *, 0x24);
            temp_f3 = M2C_FIELD(var_v1, f32 *, 0x24) * M2C_FIELD(temp_s0, f32 *, 0x28);
            temp_f2_2 = M2C_FIELD(var_v1, f32 *, 0x20);
            var_v1 += 0x34;
            *(f32 *)var_a0 = (temp_f0_2 - temp_f3) + (temp_f2_2 * M2C_FIELD(temp_s0, f32 *, 0x2C));
            var_a0 += 0xEC;
        } while (var_a1_2 < (s32) M2C_FIELD(temp_v0, u8 *, 1));
    }
    func_0036A080(arg0, var_a1_2, temp_v0, M2C_FIELD(temp_s0, f32 *, 0x5B4));
    M2C_FIELD(temp_s0, s8 *, 0x4B5) = func_0036A1D8(arg0, 0);
}
