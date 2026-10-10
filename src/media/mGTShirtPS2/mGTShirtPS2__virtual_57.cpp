#include "gt4/mGTShirtPS2.h"
typedef int s32;

extern "C" void func_001C3958(struct mGTShirtPS2 *arg0);

extern "C" void mGTShirtPS2__virtual_57(struct mGTShirtPS2 *arg0, s32 arg1) {
    arg0->unk23C = arg1;
    func_001C3958(arg0);
}
