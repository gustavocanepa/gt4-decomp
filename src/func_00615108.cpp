typedef long long s64;

struct __attribute__((aligned(8))) S00615108 {
    char pad[0x10];
    s64 unk10;
};

extern "C" void *func_00615108(struct S00615108 *arg0) {
    arg0->unk10 = (arg0->unk10 & ~0x70LL) | 0x40;
    return arg0;
}
