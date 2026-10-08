typedef int s32;

struct Obj {
    char pad[0x18];
    s32 unk18;
};

extern "C" void func_00454410(s32 arg0);

extern "C" void func_00395198(Obj *arg0, s32 arg1) {
    func_00454410(arg1);
    arg0->unk18 = arg1;
}
