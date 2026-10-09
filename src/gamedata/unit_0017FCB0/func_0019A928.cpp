struct Inner {
    char pad[0x44];
    volatile int unk44;
};

struct Obj {
    char pad[0xA0];
    Inner *unkA0;
};

extern "C" void func_0019A928(Obj *arg0) {
    Inner *v0 = arg0->unkA0;
    v0->unk44 = 1;
    v0->unk44;
}
