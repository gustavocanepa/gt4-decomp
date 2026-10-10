#include "gt4/mStorageMC.h"
typedef int s32;

extern "C" s32 func_0054C748(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern "C" s32 mStorageMC__virtual_55(struct mStorageMC *arg0, s32 arg1, s32 arg2, s32 arg3) {
    return func_0054C748(arg0->unk10 - 1, arg1, arg2, arg3, 0);
}
