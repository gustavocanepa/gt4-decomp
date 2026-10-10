#include "gt4/RaceEventQueue.h"
extern "C" void func_003B7470(void *arg0);
extern "C" void func_00576090(void);
extern "C" char RaceEventQueue__vtable[];

extern "C" void RaceEventQueue__structor_0(struct RaceEventQueue *arg0) {
    arg0->unk828 = RaceEventQueue__vtable;
    func_00576090();
    return func_003B7470(arg0);
}
