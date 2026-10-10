#include "gt4/RaceCapacityMonitor.h"
extern "C" void RaceDisplayObjectBase__structor_1(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *RaceCapacityMonitor__vtable;

extern "C" void RaceCapacityMonitor__structor_1(struct RaceCapacityMonitor *arg0, int arg1) {
    arg0->unk14 = &RaceCapacityMonitor__vtable;
    RaceDisplayObjectBase__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
