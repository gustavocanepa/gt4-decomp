typedef long long s64;

struct __attribute__((aligned(8))) S006150E8 {
    char pad[0x10];
    s64 unk10;
};

extern "C" void *func_006150E8(struct S006150E8 *arg0) {
    arg0->unk10 = (arg0->unk10 & ~0x70LL) | 0x10;
    return arg0;
}
