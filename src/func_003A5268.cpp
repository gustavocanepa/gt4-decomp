typedef int s32;

struct S003A5268 {
    char pad0[0x2C];
    s32 unk2C;
};

extern "C" void func_005A609C(void *arg0);

extern "C" void func_003A5268(struct S003A5268 *arg0, s32 arg1, s32 arg2) {
    arg0->unk2C = arg2;
    func_005A609C((char *)arg0 + 0x30);
}
