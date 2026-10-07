typedef int s32;

struct Obj {
    char pad[0x14];
    void *unk14;
};

extern "C" char D_00686100;
extern "C" void func_003FF9A0(Obj *arg0, s32 arg1);
extern "C" void func_005C1628(Obj *arg0);

extern "C" void func_003FF940(Obj *arg0, s32 arg1) {
    arg0->unk14 = &D_00686100;
    func_003FF9A0(arg0, arg1);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
