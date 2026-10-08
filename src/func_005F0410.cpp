typedef int s32;

struct Inner {
    char pad0[0x14];
    s32 unk14;
    char pad1[0x20 - 0x18];
    s32 unk20;
};

struct Obj {
    char pad0[0x2C];
    Inner *unk2C;
};

extern "C" s32 func_005F0410(Obj *arg0) {
    Inner *inner = arg0->unk2C;
    s32 v = inner->unk20 - 1;
    inner->unk20 = v;
    return inner->unk14 + (v * 4);
}
