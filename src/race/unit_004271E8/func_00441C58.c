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

void func_00441C58(M2C_UNK arg0, void *arg1, void *arg2) {
    M2C_FIELD(arg1, u16 *, 0xD8) = (u16) M2C_FIELD(arg2, u16 *, 0x1E);
    M2C_FIELD(arg1, u16 *, 0xDA) = (u16) M2C_FIELD(arg2, u16 *, 0x20);
    M2C_FIELD(arg1, u16 *, 0xDC) = (u16) M2C_FIELD(arg2, u16 *, 0x22);
    M2C_FIELD(arg1, u16 *, 0xDE) = (u16) M2C_FIELD(arg2, u16 *, 0x24);
    M2C_FIELD(arg1, u16 *, 0xE0) = (u16) M2C_FIELD(arg2, u16 *, 0x26);
    M2C_FIELD(arg1, u16 *, 0xE2) = (u16) M2C_FIELD(arg2, u16 *, 0x28);
    M2C_FIELD(arg1, u16 *, 0xE4) = (u16) M2C_FIELD(arg2, u16 *, 0x2A);
    M2C_FIELD(arg1, u16 *, 0xE6) = (u16) M2C_FIELD(arg2, u16 *, 0x2C);
    M2C_FIELD(arg1, u16 *, 0xE8) = (u16) M2C_FIELD(arg2, u16 *, 0x2E);
    M2C_FIELD(arg1, u16 *, 0xEA) = (u16) M2C_FIELD(arg2, u16 *, 0x30);
    M2C_FIELD(arg1, u16 *, 0xEC) = (u16) M2C_FIELD(arg2, u16 *, 0x32);
    M2C_FIELD(arg1, u16 *, 0xEE) = (u16) M2C_FIELD(arg2, u16 *, 0x34);
    M2C_FIELD(arg1, u16 *, 0xF0) = (u16) M2C_FIELD(arg2, u16 *, 0x36);
    M2C_FIELD(arg1, u16 *, 0xF2) = (u16) M2C_FIELD(arg2, u16 *, 0x38);
    M2C_FIELD(arg1, u16 *, 0xF4) = (u16) M2C_FIELD(arg2, u16 *, 0x3A);
    M2C_FIELD(arg1, u16 *, 0xF6) = (u16) M2C_FIELD(arg2, u16 *, 0x3C);
    M2C_FIELD(arg1, u16 *, 0xF8) = (u16) M2C_FIELD(arg2, u16 *, 0x3E);
    M2C_FIELD(arg1, u16 *, 0xFA) = (u16) M2C_FIELD(arg2, u16 *, 0x40);
    M2C_FIELD(arg1, u16 *, 0xFC) = (u16) M2C_FIELD(arg2, u16 *, 0x42);
    M2C_FIELD(arg1, u16 *, 0xFE) = (u16) M2C_FIELD(arg2, u16 *, 0x44);
    M2C_FIELD(arg1, u16 *, 0x100) = (u16) M2C_FIELD(arg2, u16 *, 0x46);
    M2C_FIELD(arg1, u16 *, 0x102) = (u16) M2C_FIELD(arg2, u16 *, 0x48);
    M2C_FIELD(arg1, u16 *, 0x104) = (u16) M2C_FIELD(arg2, u16 *, 0x4A);
    M2C_FIELD(arg1, u16 *, 0x106) = (u16) M2C_FIELD(arg2, u16 *, 0x4C);
    M2C_FIELD(arg1, u8 *, 0xC0) = (u8) M2C_FIELD(arg2, u8 *, 0x55);
    M2C_FIELD(arg1, u8 *, 0xC1) = (u8) M2C_FIELD(arg2, u8 *, 0x56);
    M2C_FIELD(arg1, u8 *, 0xC2) = (u8) M2C_FIELD(arg2, u8 *, 0x57);
    M2C_FIELD(arg1, u8 *, 0xC3) = (u8) M2C_FIELD(arg2, u8 *, 0x58);
    M2C_FIELD(arg1, u8 *, 0xC4) = (u8) M2C_FIELD(arg2, u8 *, 0x59);
    M2C_FIELD(arg1, u8 *, 0xC5) = (u8) M2C_FIELD(arg2, u8 *, 0x5A);
    M2C_FIELD(arg1, u8 *, 0xC6) = (u8) M2C_FIELD(arg2, u8 *, 0x5B);
    M2C_FIELD(arg1, u8 *, 0xC7) = (u8) M2C_FIELD(arg2, u8 *, 0x5C);
    M2C_FIELD(arg1, u8 *, 0xC8) = (u8) M2C_FIELD(arg2, u8 *, 0x5D);
    M2C_FIELD(arg1, u8 *, 0xC9) = (u8) M2C_FIELD(arg2, u8 *, 0x5E);
    M2C_FIELD(arg1, u8 *, 0xCA) = (u8) M2C_FIELD(arg2, u8 *, 0x5F);
    M2C_FIELD(arg1, u8 *, 0xCB) = (u8) M2C_FIELD(arg2, u8 *, 0x60);
    M2C_FIELD(arg1, u8 *, 0xCC) = (u8) M2C_FIELD(arg2, u8 *, 0x61);
    M2C_FIELD(arg1, u8 *, 0xCD) = (u8) M2C_FIELD(arg2, u8 *, 0x62);
    M2C_FIELD(arg1, u8 *, 0xCE) = (u8) M2C_FIELD(arg2, u8 *, 0x63);
    M2C_FIELD(arg1, u8 *, 0xCF) = (u8) M2C_FIELD(arg2, u8 *, 0x64);
    M2C_FIELD(arg1, u8 *, 0xD0) = (u8) M2C_FIELD(arg2, u8 *, 0x65);
    M2C_FIELD(arg1, u8 *, 0xD1) = (u8) M2C_FIELD(arg2, u8 *, 0x66);
    M2C_FIELD(arg1, u8 *, 0xD2) = (u8) M2C_FIELD(arg2, u8 *, 0x67);
    M2C_FIELD(arg1, u8 *, 0xD3) = (u8) M2C_FIELD(arg2, u8 *, 0x68);
    M2C_FIELD(arg1, u8 *, 0xD4) = (u8) M2C_FIELD(arg2, u8 *, 0x69);
    M2C_FIELD(arg1, u8 *, 0xD5) = (u8) M2C_FIELD(arg2, u8 *, 0x6A);
    M2C_FIELD(arg1, u8 *, 0xD6) = (u8) M2C_FIELD(arg2, u8 *, 0x6B);
    M2C_FIELD(arg1, u8 *, 0xD7) = (u8) M2C_FIELD(arg2, u8 *, 0x6C);
    M2C_FIELD(arg1, s16 *, 0x108) = (s16) (M2C_FIELD(arg2, u8 *, 0x6F) * 0xA);
    M2C_FIELD(arg1, u8 *, 0x160) = (u8) M2C_FIELD(arg2, u8 *, 0x53);
    M2C_FIELD(arg1, u8 *, 0xBC) = (u8) M2C_FIELD(arg2, u8 *, 0x52);
    M2C_FIELD(arg1, u8 *, 0xBD) = (u8) M2C_FIELD(arg2, u8 *, 0x51);
    M2C_FIELD(arg1, u8 *, 0xBE) = (u8) M2C_FIELD(arg2, u8 *, 0x50);
    M2C_FIELD(arg1, u8 *, 0xBF) = (u8) M2C_FIELD(arg2, u8 *, 0x54);
    M2C_FIELD(arg1, u8 *, 0x110) = (u8) M2C_FIELD(arg2, u8 *, 0x6D);
    M2C_FIELD(arg1, u8 *, 0x111) = (u8) M2C_FIELD(arg2, u8 *, 0x6E);
}
