typedef int s32;

struct Inner {
    char pad[0x70];
    s32 unk70;
};

struct Obj {
    char pad[0xA0];
    Inner *unkA0;
};

extern "C" s32 func_0019A820(Obj *arg0) {
    return arg0->unkA0->unk70;
}
