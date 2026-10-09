typedef int s32;

struct Obj {
    char pad[0x808];
    char buf808[0x1C];
    char pad2[0x824 - 0x808 - 0x1C];
    s32 unk824;
};

extern "C" void func_005A48D8(void *arg0, s32 arg1, s32 arg2);

extern "C" void func_003B7470(Obj *arg0) {
    arg0->unk824 = 0;
    func_005A48D8(arg0->buf808, 0, 0x1C);
}
