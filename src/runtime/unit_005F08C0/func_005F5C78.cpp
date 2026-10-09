typedef long long s64;

struct S005F5C78 {
    char pad0[0x268];
    s64 unk268;
};

extern "C" void func_005F5C78(struct S005F5C78 *arg0) {
    arg0->unk268 = (arg0->unk268 & ~0xFFLL) | 1LL;
}
