#include "gt4/RaceCapacityMonitor.h"
typedef int s32;

extern void *RaceCapacityMonitor__vtable;
extern "C" void RaceDisplayObjectBase__structor_0(void *);

extern "C" void RaceCapacityMonitor__structor_0(struct RaceCapacityMonitor *arg0) {
    RaceDisplayObjectBase__structor_0(arg0);
    void *p0 = arg0->unk24;
    arg0->unk14 = &RaceCapacityMonitor__vtable;
    arg0->unk24 = (void *)(((s32)p0 & (s32)-0x100));
    arg0->unk1C = 0x0;
    arg0->unk20 = 0x0;
    arg0->unk18 = 0x0;
}
