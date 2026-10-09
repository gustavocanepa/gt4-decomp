typedef int s32;

struct Inner {
    char pad[0xB0];
    s32 unkB0;
};

struct Obj {
    char pad[0x4];
    Inner *unk4;
};

extern "C" s32 func_003DDFF0(s32 arg0);

extern "C" s32 func_00396078(Obj *arg0) {
    return func_003DDFF0(arg0->unk4->unkB0);
}
