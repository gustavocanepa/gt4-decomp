#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

extern char mMovieFace__vtable[];
s32 mImageFace__structor_0(void *);
void func_00220730(void *);
void *func_0021D7F8(void *, s32 *);
struct mMovieFace__structor_0_arg0 {
    char pad0[0x4];
    s32 unk4;
    char pad8[0x110];
    s8 unk118;
    char pad119[0x3F];
    s32 unk158;
    s32 unk15C;
};

void mMovieFace__structor_0(s8 *arg0) {
    s32 sp[4];
    mImageFace__structor_0(arg0);
    ((struct mMovieFace__structor_0_arg0 *)arg0)->unk4 = (s32)mMovieFace__vtable;
    func_00220730(arg0 + 0xF0);
    sp[0] = 0;
    func_0021D7F8(arg0 + 0x114, sp);
    ((struct mMovieFace__structor_0_arg0 *)arg0)->unk158 = -1;
    ((struct mMovieFace__structor_0_arg0 *)arg0)->unk15C = 0;
    ((struct mMovieFace__structor_0_arg0 *)arg0)->unk118 = 0;
}
