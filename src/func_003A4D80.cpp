typedef int s32;

struct S003A4D80 {
    char pad0[0x24];
    s32 unk24;
};

extern "C" void func_005A609C(void *arg0);

extern "C" void func_003A4D80(struct S003A4D80 *arg0, s32 arg1, s32 arg2) {
    arg0->unk24 = arg2;
    func_005A609C((char *)arg0 + 0x70);
}
