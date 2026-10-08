typedef int s32;

struct Obj {
    char pad[0x18];
    s32 unk18;
    s32 unk1C;
};

extern "C" void func_00575DA0(s32 arg0);

extern "C" void func_001C21A8(Obj *arg0) {
    func_00575DA0(arg0->unk18);
    arg0->unk18 = 0;
    func_00575DA0(arg0->unk1C);
    arg0->unk1C = 0;
}
