typedef int s32;

struct Obj {
    char pad[0x10];
    s32 unk10;
    s32 unk14;
    s32 unk18;
};

extern "C" void func_00575DA0(s32 arg0);

extern "C" void func_001C20A0(Obj *arg0) {
    func_00575DA0(arg0->unk10);
    arg0->unk10 = 0;
    arg0->unk14 = 0;
    arg0->unk18 = 0;
}
