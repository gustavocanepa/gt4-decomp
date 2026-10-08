typedef long long s64;

struct Obj00338760 {
    char pad[0x98];
    s64 unk98;
    char pad2[0x110 - 0xA0];
    s64 unk110;
};

extern "C" s64 func_00447188(struct Obj00338760 *arg0);

extern "C" void func_00338760(struct Obj00338760 *arg0) {
    struct Obj00338760 *s0 = arg0;

    func_00447188(arg0);
    s0->unk110 = s0->unk98;
}
