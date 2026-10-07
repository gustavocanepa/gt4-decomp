typedef int s32;

struct Obj {
    char pad[0x18];
    void *unk18;
};

extern "C" char D_006888A8;
extern "C" void func_00575B68(Obj *arg0, s32 arg1);
extern "C" void func_005C1628(Obj *arg0);

extern "C" void func_00575B08(Obj *arg0, s32 arg1) {
    arg0->unk18 = &D_006888A8;
    func_00575B68(arg0, arg1);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
