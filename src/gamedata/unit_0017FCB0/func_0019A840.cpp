typedef int s32;

struct Inner {
    char pad[0x78];
    s32 unk78;
};

struct Obj {
    char pad[0xA0];
    Inner *unkA0;
};

extern "C" s32 func_0019A840(Obj *arg0) {
    return arg0->unkA0->unk78;
}
