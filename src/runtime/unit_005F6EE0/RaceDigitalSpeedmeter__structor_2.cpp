#include "gt4/RaceDigitalSpeedmeter.h"
extern "C" void RaceDisplayObjectBase__structor_1(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *RaceDigitalSpeedmeter__vtable;

extern "C" void RaceDigitalSpeedmeter__structor_2(struct RaceDigitalSpeedmeter *arg0, int arg1) {
    arg0->unk14 = &RaceDigitalSpeedmeter__vtable;
    RaceDisplayObjectBase__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
