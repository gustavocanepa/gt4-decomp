typedef int s32;

struct Inner003EB718 {
    char pad0[0xE0];
    s32 unkE0;
};

struct Obj003EB718 {
    char pad0[0x6C];
    Inner003EB718 *unk6C;
};

extern "C" void func_0038B5A0(Obj003EB718 *arg0);

extern "C" void func_003EB718(Obj003EB718 *arg0) {
    if (arg0->unk6C->unkE0 == 0) {
        return func_0038B5A0(arg0);
    }
}
