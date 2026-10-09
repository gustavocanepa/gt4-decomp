typedef int s32;
typedef long long s64;

struct Obj {
    char pad0[0x70];
    s32 unk70;
    char pad1[0x78 - 0x74];
    s64 unk78;
};

extern "C" void func_00447238(s32 arg0);

extern "C" void func_003C0C20(Obj *arg0, s64 arg1) {
    arg0->unk78 = arg1;
    func_00447238(arg0->unk70);
}
