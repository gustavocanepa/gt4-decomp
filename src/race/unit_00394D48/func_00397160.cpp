typedef int s32;

struct Obj {
    char pad[0x44];
    s32 unk44;
    s32 unk48;
};

extern "C" void func_00397188(Obj *arg0, s32 arg1, s32 arg2);

extern "C" void func_00397160(Obj *arg0) {
    func_00397188(arg0, arg0->unk44, arg0->unk48);
}
