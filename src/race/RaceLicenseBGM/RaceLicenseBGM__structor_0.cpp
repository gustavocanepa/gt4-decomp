#include "gt4/RaceLicenseBGM.h"
extern "C" void *RaceBGMPS2__structor_0(void *arg0);
extern "C" char RaceLicenseBGM__vtable[];

extern "C" void RaceLicenseBGM__structor_0(struct RaceLicenseBGM *arg0)
{
    RaceBGMPS2__structor_0(arg0);
    arg0->unk4 = RaceLicenseBGM__vtable;
    arg0->unk11E8 = 0;
}
