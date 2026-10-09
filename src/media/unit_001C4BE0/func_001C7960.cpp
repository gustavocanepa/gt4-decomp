typedef int s32;

struct Obj {
    char pad0[0x11D4];
    char pad1[0x11F4 - 0x11D4];
    s32 unk11F4;
    s32 unk11F8;
    s32 unk11FC;
};

extern "C" void func_0046CEE8(Obj *arg0);
extern "C" void func_001C5D70(void *arg0);

extern "C" void func_001C7960(Obj *arg0) {
    func_0046CEE8(arg0);
    func_001C5D70((char *)arg0 + 0x11D4);
    arg0->unk11F4 = 0;
    arg0->unk11F8 = 0;
    arg0->unk11FC = 0;
}
