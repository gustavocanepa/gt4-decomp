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

s32 func_004452A8(s32, s32, s32, s32);
M2C_UNK func_0043FFE0(void *, void *);                      /* extern */

void func_004404B8(void *arg0, s64 arg1, void *arg2) {
    u8 temp_s2;
    u8 temp_s2_2;
    u8 temp_s2_3;
    u8 temp_s2_4;
    void *temp_s0;

    temp_s0 = arg0 + (M2C_FIELD(arg0, s32 *, 0x490) * 0x178) + 8;
    M2C_FIELD(temp_s0, s64 *, 0x50) = arg1;
    func_0043FFE0(arg0, arg2);
    M2C_FIELD(temp_s0, u8 *, 0x140) = (u8) M2C_FIELD(arg2, u8 *, 0xAD);
    M2C_FIELD(temp_s0, u8 *, 0x141) = (u8) M2C_FIELD(arg2, u8 *, 0xB0);
    M2C_FIELD(temp_s0, s8 *, 0x139) = func_004452A8((s32) temp_s0, (s32) M2C_FIELD(arg2, u8 *, 0x93), (s32) M2C_FIELD(arg2, u8 *, 0x95), (s32) M2C_FIELD(arg2, u8 *, 0x94));
    M2C_FIELD(temp_s0, s8 *, 0x13A) = func_004452A8((s32) temp_s0, (s32) M2C_FIELD(arg2, u8 *, 0x96), (s32) M2C_FIELD(arg2, u8 *, 0x98), (s32) M2C_FIELD(arg2, u8 *, 0x97));
    M2C_FIELD(temp_s0, s16 *, 0x13C) = func_004452A8((s32) temp_s0, (s32) M2C_FIELD(arg2, u16 *, 0x84), (s32) M2C_FIELD(arg2, u16 *, 0x88), (s32) M2C_FIELD(arg2, u16 *, 0x86));
    M2C_FIELD(temp_s0, s16 *, 0x13E) = func_004452A8((s32) temp_s0, (s32) M2C_FIELD(arg2, u16 *, 0x8A), (s32) M2C_FIELD(arg2, u16 *, 0x8E), (s32) M2C_FIELD(arg2, u16 *, 0x8C));
    M2C_FIELD(temp_s0, s8 *, 0x142) = func_004452A8((s32) temp_s0, (s32) M2C_FIELD(arg2, u8 *, 0xB8), (s32) M2C_FIELD(arg2, u8 *, 0xBA), (s32) M2C_FIELD(arg2, u8 *, 0xB9));
    M2C_FIELD(temp_s0, s8 *, 0x143) = func_004452A8((s32) temp_s0, (s32) M2C_FIELD(arg2, u8 *, 0xBB), (s32) M2C_FIELD(arg2, u8 *, 0xBD), (s32) M2C_FIELD(arg2, u8 *, 0xBC));
    M2C_FIELD(temp_s0, u8 *, 0x144) = (u8) M2C_FIELD(arg2, u8 *, 0xBE);
    M2C_FIELD(temp_s0, u8 *, 0x145) = (u8) M2C_FIELD(arg2, u8 *, 0xBF);
    temp_s2 = M2C_FIELD(arg2, u8 *, 0xCC);
    M2C_FIELD(temp_s0, s8 *, 0x146) = func_004452A8((s32) temp_s0, 1, (s32) M2C_FIELD(arg2, u8 *, 0xCF), (s32) temp_s2);
    M2C_FIELD(temp_s0, s8 *, 0x147) = func_004452A8((s32) temp_s0, 1, (s32) M2C_FIELD(arg2, u8 *, 0xD2), (s32) temp_s2);
    temp_s2_2 = M2C_FIELD(arg2, u8 *, 0xD3);
    M2C_FIELD(temp_s0, s8 *, 0x148) = func_004452A8((s32) temp_s0, 1, (s32) M2C_FIELD(arg2, u8 *, 0xD6), (s32) temp_s2_2);
    M2C_FIELD(temp_s0, s8 *, 0x149) = func_004452A8((s32) temp_s0, 1, (s32) M2C_FIELD(arg2, u8 *, 0xD9), (s32) temp_s2_2);
    temp_s2_3 = M2C_FIELD(arg2, u8 *, 0xDA);
    M2C_FIELD(temp_s0, s8 *, 0x14A) = func_004452A8((s32) temp_s0, 1, (s32) M2C_FIELD(arg2, u8 *, 0xDD), (s32) temp_s2_3);
    M2C_FIELD(temp_s0, s8 *, 0x14B) = func_004452A8((s32) temp_s0, 1, (s32) M2C_FIELD(arg2, u8 *, 0xE0), (s32) temp_s2_3);
    temp_s2_4 = M2C_FIELD(arg2, u8 *, 0xE1);
    M2C_FIELD(temp_s0, s8 *, 0x14C) = func_004452A8((s32) temp_s0, 1, (s32) M2C_FIELD(arg2, u8 *, 0xE4), (s32) temp_s2_4);
    M2C_FIELD(temp_s0, s8 *, 0x14D) = func_004452A8((s32) temp_s0, 1, (s32) M2C_FIELD(arg2, u8 *, 0xE7), (s32) temp_s2_4);
    M2C_FIELD(temp_s0, s8 *, 0x14E) = func_004452A8((s32) temp_s0, 1, (s32) M2C_FIELD(arg2, u8 *, 0xED), (s32) M2C_FIELD(arg2, u8 *, 0xEA));
    M2C_FIELD(temp_s0, s8 *, 0x14F) = func_004452A8((s32) temp_s0, 1, (s32) M2C_FIELD(arg2, u8 *, 0xF1), (s32) M2C_FIELD(arg2, u8 *, 0xEE));
}
