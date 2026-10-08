typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64;
typedef float f32; typedef double f64;
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

void *func_00359510(s32);                           /* extern */

void func_00363018(void *arg0) {
    s32 var_a1;
    void *temp_v0;
    void *var_a0;

    temp_v0 = func_00359510(M2C_FIELD(arg0, s32 *, 0x10));
    var_a1 = 0;
    if (M2C_FIELD(temp_v0, u8 *, 1) != 0) {
        var_a0 = arg0 + 0x164;
        do {
            M2C_FIELD(var_a0, s32 *, 0xBC) = 0;
            var_a1 += 1;
            M2C_FIELD(var_a0, s8 *, 0xB2) = -1;
            M2C_FIELD(var_a0, s32 *, 0xB4) = 0;
            M2C_FIELD(var_a0, f32 *, 0xB8) = 1.0f;
            M2C_FIELD(var_a0, s32 *, 0x24) = 0;
            M2C_FIELD(var_a0, s32 *, 0x40) = 0;
            M2C_FIELD(var_a0, s32 *, 0x38) = 0;
            M2C_FIELD(var_a0, s32 *, 0x58) = 0;
            M2C_FIELD(var_a0, s32 *, 0x90) = 0;
            M2C_FIELD(var_a0, s32 *, 0x98) = 0;
            M2C_FIELD(var_a0, s32 *, 0x9C) = 0;
            M2C_FIELD(var_a0, s32 *, 0xA0) = 0;
            M2C_FIELD(var_a0, s32 *, 0xC0) = 0;
            M2C_FIELD(var_a0, s32 *, 0xC4) = 0;
            M2C_FIELD(var_a0, s32 *, 0x5C) = 0;
            M2C_FIELD(var_a0, s32 *, 0xCC) = 0;
            M2C_FIELD(var_a0, s32 *, 0xD0) = 0;
            M2C_FIELD(var_a0, s32 *, 0xD4) = 0;
            var_a0 += 0xEC;
        } while (var_a1 < (s32) M2C_FIELD(temp_v0, u8 *, 1));
    }
}
