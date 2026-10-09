typedef int s32;

struct Inner {
    char pad[0x10];
    s32 unk10;
};

struct Obj {
    char pad[0xA0];
    Inner *unkA0;
};

extern "C" void func_0019A898(Obj *arg0, s32 arg1) {
    arg0->unkA0->unk10 = arg1 ^ 1;
}
