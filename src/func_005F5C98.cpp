typedef long long s64;

struct Obj {
    char pad[0x268];
    s64 unk268;
};

extern "C" void func_005F5C98(Obj *arg0) {
    arg0->unk268 = (arg0->unk268 & ~(0xFFLL << 8)) | (1LL << 8);
}
