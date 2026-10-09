typedef int s32;

struct Obj {
    char pad[0x18];
    void *unk18;
};

extern "C" char _UnitArenaBase__vtable;
extern "C" void func_00463840(Obj *arg0, s32 arg1);
extern "C" void func_005C1628(Obj *arg0);

extern "C" void _UnitArenaBase__structor_0(Obj *arg0, s32 arg1) {
    arg0->unk18 = &_UnitArenaBase__vtable;
    func_00463840(arg0, arg1);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
