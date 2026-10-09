typedef int s32;

struct Elem {
    s32 unk0;
    char pad[0x10 - 4];
};

struct Inner {
    char pad[0x1C];
    Elem *unk1C;
};

struct Obj {
    char pad[0x4];
    Inner *unk4;
};

extern "C" s32 func_0042A0E8(Obj *arg0, s32 arg1) {
    return arg0->unk4->unk1C[arg1].unk0;
}
