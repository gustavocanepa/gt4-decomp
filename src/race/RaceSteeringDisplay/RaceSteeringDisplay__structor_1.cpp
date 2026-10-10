#include "gt4/RaceSteeringDisplay.h"
typedef int s32;

extern void *RaceSteeringDisplay__vtable;
extern "C" void RaceDisplayObjectBase__structor_0(void *);

extern "C" void RaceSteeringDisplay__structor_1(struct RaceSteeringDisplay *arg0) {
    RaceDisplayObjectBase__structor_0(arg0);
    arg0->unk14 = &RaceSteeringDisplay__vtable;
    arg0->unk20 = *(float *)((char *)"GTMODE_MACHINE_TEST_MAX_SPEED" + 0x14c0);
    arg0->unk1C_pvoid = 0x0;
    arg0->unk18 = 0x0;
}
