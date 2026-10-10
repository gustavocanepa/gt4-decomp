/* compiler: ee-gcc2.96-nosib */
#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
#include "m2c_macros.h"

typedef signed char s8; typedef unsigned char u8; typedef short s16; typedef unsigned short u16;
typedef int s32; typedef unsigned int u32; typedef long long s64; typedef unsigned long long u64;
typedef float f32; typedef double f64;
typedef int s128 __attribute__((mode(TI))); typedef unsigned int u128 __attribute__((mode(TI)));
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);
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

#define GLUE_F64(a, b) (0x0.0p+0)
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
#define M2C_MEMCPY_ALIGNED func_005A4724
#define M2C_MEMCPY_UNALIGNED func_005A4724
#define M2C_STRUCT_COPY func_005A4724

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

struct mWidget {
    s32 unk0;
    void * unk4;
    s32 unk8;
    void * unkC;
    s32 unk10;
    s32 unk14;
    char unk_18[0x10];
    s32 unk28;
    s32 unk2C;
    char unk_30[0x24];
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    char unk_60[0x4];
    void * unk64;
    char unk_68[0xC];
    f32 unk74;
    f32 unk78;
    char unk_7C[0xC];
    f32 unk88;
    void * unk8C;
    void * unk90;
    void * unk94;
    s32 unk98;
    s32 unk9C;
    char unk_A0[0x4];
    s32 unkA4;
};
struct mSelectBox {
    s32 unk0;
    void * unk4;
    s32 unk8;
    void * unkC;
    s32 unk10;
    s32 unk14;
    char unk_18[0x10];
    s32 unk28;
    s32 unk2C;
    char unk_30[0x24];
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    char unk_60[0x4];
    void * unk64;
    char unk_68[0xC];
    f32 unk74;
    f32 unk78;
    char unk_7C[0xC];
    f32 unk88;
    void * unk8C;
    void * unk90;
    void * unk94;
    s32 unk98;
    s32 unk9C;
    s32 unkA0;
    s32 unkA4;
    s32 unkA8;
    s32 unkAC;
    s32 unkB0;
    char unk_B4[0x8];
    s32 unkBC;
    char unk_C0[0x10];
    f32 unkD0;
    f32 unkD4;
    s32 unkD8;
    s32 unkDC;
    s32 unkE0;
    f32 unkE4;
    f32 unkE8;
    f32 unkEC;
    s32 unkF0;
};
struct mComposite {
    s32 unk0;
    void * unk4;
    s32 unk8;
    void * unkC;
    s32 unk10;
    s32 unk14;
    char unk_18[0x10];
    s32 unk28;
    s32 unk2C;
    char unk_30[0x24];
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    char unk_60[0x4];
    void * unk64;
    char unk_68[0xC];
    f32 unk74;
    f32 unk78;
    char unk_7C[0xC];
    f32 unk88;
    void * unk8C;
    void * unk90;
    void * unk94;
    s32 unk98;
    s32 unk9C;
    s32 unkA0;
    s32 unkA4;
    s32 unkA8;
    s32 unkAC;
};
s32 func_00206880(struct mWidget *);
f32 mWidget__getWindowW(void *);
f32 mWidget__getWindowH(void *);
void mSelectBox__virtual_99(struct mSelectBox *arg0, s32 arg1, s32 arg2) {
    if (func_00206880((struct mWidget *) arg0) == 0) {
        arg0->unkE4 = mWidget__getWindowW((void *) arg2);
        arg0->unkE8 = mWidget__getWindowH((void *) arg2);
    }
    mPhotoMapWindow__virtual_99((struct mComposite *) arg0, arg1, arg2);
    func_002DA5D0(arg0);
}
