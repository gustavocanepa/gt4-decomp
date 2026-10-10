#include "gt4/DynamicsConductorBattle2P.h"
typedef int s32;

extern "C" s32 func_00395420(s32 arg0, s32 arg1);

extern "C" s32 DynamicsConductorBattle2P__virtual_41(struct DynamicsConductorBattle2P *arg0) {
    s32 temp_v0;

    temp_v0 = func_00395420(arg0->unkCBD8, 0) + 1;
    return (temp_v0 >= 0x11) ? 0x10 : temp_v0;
}
