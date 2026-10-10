#include "gt4/EyeToyPS2.h"
typedef int s32;

extern "C" void func_005C1628(struct EyeToyPS2 *arg0);
extern "C" char EyeToyPS2__vtable;

extern "C" void EyeToyPS2__structor_1(struct EyeToyPS2 *arg0, s32 arg1)
{
    arg1 = arg1 & 1;
    arg0->unk298 = (s32)&EyeToyPS2__vtable;
    if (arg1)
    {
        func_005C1628(arg0);
        return;
    }
}
