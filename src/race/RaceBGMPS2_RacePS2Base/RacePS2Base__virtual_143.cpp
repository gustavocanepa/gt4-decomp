#include "gt4/RacePS2Base.h"
typedef int s32;

struct Obj;
extern "C" void func_00387E40(Obj *arg0, s32 arg1);

extern "C" void RacePS2Base__virtual_143(struct RacePS2Base *arg0) {
    arg0->unkCF4C_s32 = 0;
    func_00387E40((Obj *)arg0, 2);
}
