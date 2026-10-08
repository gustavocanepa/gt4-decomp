typedef int s32;

struct Obj;

extern "C" void func_00437408(Obj *arg0, s32 arg1, s32 arg2);

extern "C" void func_00601D38(Obj *arg0, s32 arg1) {
    func_00437408(arg0, 0x400, arg1 > 0);
}
