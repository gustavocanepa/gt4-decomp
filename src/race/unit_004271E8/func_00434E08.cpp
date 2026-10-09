typedef long long s64;

struct __attribute__((aligned(8))) Obj {
    char pad[0x8];
    s64 unk8;
};

extern "C" void func_00434E08(Obj *arg0) {
    arg0->unk8 = arg0->unk8 & ~1;
}
