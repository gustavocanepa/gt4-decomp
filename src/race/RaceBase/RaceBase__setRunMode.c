#include "types.h"
void *func_005A4724(void *, const void *, unsigned int);

struct func_00387CF0_arg0 {
    char pad0[0xCC0];
    u32 unkCC0;
    u32 unkCC4;
    u32 unkCC8;
    s32 unkCCC;
};

void RaceBase__setRunMode(struct func_00387CF0_arg0 *arg0, u32 arg1) {
    s32 var_v1;

    arg0->unkCC0 = arg1;
    arg0->unkCC8 = arg1;
    if (arg1 < 2U) {
        arg0->unkCC4 = arg1;
    }
    arg0->unkCCC = 0;
    var_v1 = 0;
    if ((arg1 == 1) || (arg1 == 3)) {
        var_v1 = 1;
    }
    if (var_v1 != 0) {
        arg0->unkCCC = 1;
    }
}
