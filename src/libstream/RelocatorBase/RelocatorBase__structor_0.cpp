#include "gt4/RelocatorBase.h"
typedef int s32;

extern "C" char RelocatorBase__vtable[];

extern "C" void RelocatorBase__structor_0(struct RelocatorBase *arg0) {
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
    arg0->unk10 = RelocatorBase__vtable;
    arg0->unkC = 0;
}
