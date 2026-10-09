typedef int s32;

struct Obj {
    char pad[0x14];
    void *unk14;
};

extern "C" char RaceDisplayObjectBase__vtable;
extern "C" void RaceMiniMap__virtual_02(Obj *arg0, s32 arg1);
extern "C" void func_005C1628(Obj *arg0);

extern "C" void RaceDisplayObjectBase__structor_1(Obj *arg0, s32 arg1) {
    arg0->unk14 = &RaceDisplayObjectBase__vtable;
    RaceMiniMap__virtual_02(arg0, arg1);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
