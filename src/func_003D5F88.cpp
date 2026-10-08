typedef unsigned int u32;

struct Obj003D5F88 {
    char pad[0xCC8];
    u32 unkCC8;
};

extern "C" void func_0038A770();
extern "C" void func_00426BF8(void *arg0, u32 arg1);

extern "C" void func_003D5F88(struct Obj003D5F88 *arg0) {
    struct Obj003D5F88 *s0 = arg0;
    func_0038A770();
    func_00426BF8((char *)s0 + 0x123CC, s0->unkCC8);
}
