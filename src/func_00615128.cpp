typedef long long s64;

struct __attribute__((aligned(8))) S00615128 {
    char pad[0x10];
    s64 unk10;
};

extern "C" void *func_00615128(struct S00615128 *arg0) {
    arg0->unk10 = (arg0->unk10 & ~0x70LL) | 0x20;
    return arg0;
}
