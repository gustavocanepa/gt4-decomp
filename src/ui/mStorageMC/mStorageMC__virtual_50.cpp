#include "gt4/mStorageMC.h"
typedef int s32;

extern "C" s32 func_0054C7B0(s32 arg0);

extern "C" s32 mStorageMC__virtual_50(struct mStorageMC *arg0) {
    return func_0054C7B0(arg0->unk10 - 1) == 2;
}
