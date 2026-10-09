typedef int s32;

struct S001032F0 {
    char pad0[0x68];
    s32 unk68;
};

extern "C" void func_00574EE8(void *arg0);

extern "C" void func_001032F0(S001032F0 *arg0, s32 arg1) {
    arg0->unk68 = arg1;
    func_00574EE8((char *)arg0 + 0x8);
}
