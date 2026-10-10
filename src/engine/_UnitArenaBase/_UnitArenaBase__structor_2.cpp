#include "gt4/_UnitArenaBase.h"
typedef int s32;

extern "C" char _UnitArenaBase__vtable[];

extern "C" void _UnitArenaBase__structor_2(struct _UnitArenaBase *arg0, s32 arg1, s32 arg2, s32 arg3)
{
    arg0->unk0 = arg1;
    arg0->unk4 = arg2;
    arg0->unk18 = _UnitArenaBase__vtable;
    arg0->unk8 = arg3;
    arg0->unkC = 0;
    arg0->unk10 = 0;
    arg0->unk14 = 0;
}
