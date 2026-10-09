typedef int s32;

struct Obj005F8CB0 {
    char pad[0x54];
    s32 unk54;
};

extern "C" void func_005F8CB0(Obj005F8CB0 *arg0, s32 arg1) {
    arg0->unk54 = (arg0->unk54 & 0xFF00FFFF) | ((arg1 & 0xFF) << 16);
}
