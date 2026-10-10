#include "gt4/mCarModelPS2.h"
typedef int s32;

struct Struct_00156700;

extern "C" void func_00156700(struct Struct_00156700 *arg0);

extern "C" void mCarModelPS2__virtual_53(struct mCarModelPS2 *arg0, s32 arg1) {
    arg0->unk54 = arg1;
    func_00156700((struct Struct_00156700 *)arg0);
}
