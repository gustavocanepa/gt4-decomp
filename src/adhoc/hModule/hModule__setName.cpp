#include "gt4/hClass.h"
typedef int s32;

extern "C" s32 HSymID__GetID(s32 arg0);

extern "C" void hModule__setName(struct hClass *arg0, s32 arg1) {
    s32 local;
    s32 *s0 = &arg0->unk10;

    local = HSymID__GetID(arg1);
    if (s0 != &local) {
        *s0 = local;
    }
}
