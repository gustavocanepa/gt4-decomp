#include "gt4/mTryCatch.h"
typedef int s32;

extern "C" void HTryCatchFrame__structor_0(s32 arg0, s32 arg1);

extern "C" void mTryCatch__execute(struct mTryCatch *arg0, s32 arg1) {
    HTryCatchFrame__structor_0(arg1, arg0->unk8);
}
