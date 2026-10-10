#include "gt4/HumanModel.h"
typedef int s32;

extern "C" void func_004573B8(s32 arg0, s32 *arg1, struct HumanModel *arg2);

extern "C" void HumanModel__virtual_01(struct HumanModel *arg0) {
    s32 *temp_a0;

    if (arg0->unk0 != 0) {
        temp_a0 = arg0->unk6B0;
        if (temp_a0 != 0) {
            func_004573B8(*temp_a0, temp_a0, arg0);
        }
    }
}
