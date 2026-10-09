/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Built without strict aliasing: the load of arg0's first field waits for the three float stores. */
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

s32 func_00385BD8(s32);                             /* extern */
s32 func_00385BE8(s32);                             /* extern */
s32 func_00385BF8(s32);                             /* extern */
s32 func_00385C08(s32);                             /* extern */
s32 func_00385C18(s32);                             /* extern */
s32 func_00385C28(s32);                             /* extern */
s32 func_00385CB8(s32);                             /* extern */
s32 func_00385CC8(s32);                             /* extern */
s32 func_00385CD8(s32);                             /* extern */
s32 func_00385CE8(s32);                             /* extern */
s32 func_00385EE0(s32);                             /* extern */
s32 func_00385EE8(s32);                             /* extern */
M2C_UNK func_00386030(s32 *, M2C_UNK, s32);         /* extern */
s32 func_003863D8(s32);                             /* extern */
s32 func_003863E8(s32);
s32 func_00386408(s32);
s32 func_00385B68(s32);                             /* extern */
s32 func_00386418(s32);                             /* extern */
s32 func_00386428(s32);                             /* extern */
M2C_UNK func_0040FC78(M2C_UNK, f32, f32, f32, f32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32, s32 *, s32 *); /* extern */

void func_00410630(void *arg0, f32 fparg0, f32 fparg1, f32 fparg2) {
    s32 sp50;
    s32 sp54;
    s32 sp58;
    s32 sp5C;
    s32 sp60;
    s32 sp64;
    s32 sp68;
    f32 temp_f20;
    f32 temp_f0;
    s32 temp_fp;
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_s3;
    s32 temp_s4;
    s32 temp_s5;
    s32 temp_s6;
    s32 temp_s7;
    f32 *p1;
    f32 *p2;
    f32 *p3;
    f32 *p4;
    f32 *p5;
    f32 k;
    k = 0x1.0C152p-3f;
    sp50 = func_00385EE0(*M2C_FIELD(arg0, s32 **, 0xC));
    sp54 = func_00385EE8(*M2C_FIELD(arg0, s32 **, 0xC));
    temp_f20 = M2C_FIELD(arg0, f32 *, 0x110);
    sp58 = func_00385BD8(M2C_FIELD(arg0, s32 *, 0));
    sp5C = func_00385BF8(M2C_FIELD(arg0, s32 *, 0));
    sp60 = func_00385C18(M2C_FIELD(arg0, s32 *, 0));
    sp64 = func_003863D8(M2C_FIELD(arg0, s32 *, 8));
    sp68 = func_00385CB8(M2C_FIELD(arg0, s32 *, 0));
    temp_s7 = func_00385CD8(M2C_FIELD(arg0, s32 *, 0));
    temp_fp = func_00386418(M2C_FIELD(arg0, s32 *, 8));
    temp_s6 = func_00385BE8(M2C_FIELD(arg0, s32 *, 0));
    temp_s5 = func_00385C08(M2C_FIELD(arg0, s32 *, 0));
    temp_s4 = func_00385C28(M2C_FIELD(arg0, s32 *, 0));
    temp_s3 = func_003863E8(M2C_FIELD(arg0, s32 *, 8));
    temp_s2 = func_00385CC8(M2C_FIELD(arg0, s32 *, 0));
    temp_s1 = func_00385CE8(M2C_FIELD(arg0, s32 *, 0));
    func_0040FC78(0, fparg0, fparg1, temp_f20, fparg2, 0, sp58, sp5C, sp60, sp64, sp68, temp_s7, temp_fp, temp_s6, temp_s5, temp_s4, temp_s3, temp_s2, temp_s1, func_00386428(M2C_FIELD(arg0, s32 *, 8)), &sp50, &sp54);
    p1 = (f32 *)func_00385BE8(M2C_FIELD(arg0, s32 *, 0));
    p2 = (f32 *)func_00385C08(M2C_FIELD(arg0, s32 *, 0));
    p3 = (f32 *)func_003863E8(M2C_FIELD(arg0, s32 *, 8));
    p4 = (f32 *)func_00386408(M2C_FIELD(arg0, s32 *, 8));
    p5 = (f32 *)func_00385B68(M2C_FIELD(arg0, s32 *, 0));
    temp_f0 = (*p4 - *p5) + k;
    *p3 = temp_f0;
    *p2 = temp_f0;
    *p1 = temp_f0;
    *(s32 *)func_00385C28(M2C_FIELD(arg0, s32 *, 0)) = 0;
    func_00386030(M2C_FIELD(arg0, s32 **, 0xC), 0, sp50);
    func_00386030(M2C_FIELD(arg0, s32 **, 0xC), 1, sp54);
}
