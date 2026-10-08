typedef int s32;
typedef unsigned char u8;

struct Obj {
    u8 pad[0x1D00];
    s32 unk1D00;
};

extern "C" void func_00231900(Obj *arg0);

extern "C" void func_00231798(Obj *arg0) {
    func_00231900(arg0);
    arg0->unk1D00 = arg0->unk1D00 - 1;
}
