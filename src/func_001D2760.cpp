typedef int s32;

struct Obj {
    char pad[0x6E0];
    s32 unk6E0;
};

extern "C" void func_001D2650(Obj *arg0);
extern "C" void func_001D2610(Obj *arg0, s32 arg1);

extern "C" void func_001D2760(Obj *arg0) {
    if (arg0->unk6E0 == 0) {
        return func_001D2650(arg0);
    }
    func_001D2610(arg0, 0);
}
