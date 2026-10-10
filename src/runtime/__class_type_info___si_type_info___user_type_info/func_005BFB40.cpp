#include "gt4/__class_type_info.h"
/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): a function of the C++ runtime in libgcc.a (cp/tinfo.cc, tinfo2.cc, exception.cc, new*.cc), in libgcc.a's code at 0x5ba060-0x5c1ce0.
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
typedef int s32;

extern "C" char __class_type_info__vtable[];

extern "C" void func_005BFB40(struct __class_type_info *arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg0 != 0) {
        arg0->unk0 = arg1;
        arg0->unk4 = __class_type_info__vtable;
        arg0->unk8 = arg2;
        arg0->unkC = arg3;
    }
}
