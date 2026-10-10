#include "gt4/CarIconMaker.h"
extern "C" void func_00101078(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *CarIconMaker__vtable;

extern "C" void CarIconMaker__structor_2(struct CarIconMaker *arg0, int arg1) {
    arg0->unk64 = &CarIconMaker__vtable;
    func_00101078(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
