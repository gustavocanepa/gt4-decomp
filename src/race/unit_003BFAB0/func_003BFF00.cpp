typedef int s32;

struct Obj {
    char pad0[0x60];
    s32 unk60;
};

extern "C" void func_003BFE10(Obj *arg0);

extern "C" void func_003BFF00(Obj *arg0, s32 arg1) {
    func_003BFE10(arg0);
    arg0->unk60 = arg1;
}
