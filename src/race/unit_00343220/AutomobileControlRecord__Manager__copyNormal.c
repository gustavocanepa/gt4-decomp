#include "types.h"
#define NULL 0
void *func_005A4724(void *, const void *, unsigned int);

struct func_00346A40_arg0 {
    char pad0[0x4];
    s32 unk4;
};
struct func_00346A40_arg1 {
    char pad0[0x4];
    s32 unk4;
};

s32 AutomobileControlRecord__Manager__copyNormal(void *arg0, void *arg1) {
    s32 var_v1;

    var_v1 = 0;
    if ((((struct func_00346A40_arg0 *)arg0)->unk4 != 0) || (((struct func_00346A40_arg1 *)arg1)->unk4 != 0)) {
        var_v1 = 1;
    }
    if (var_v1 == 0) {
        AutomobileControlRecord__Recorder__copy(arg0 + 8, arg1 + 8);
    }
}
