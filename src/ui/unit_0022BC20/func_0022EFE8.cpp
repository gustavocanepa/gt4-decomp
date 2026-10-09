typedef int s32;

struct Inner {
    char pad[0x4];
    s32 unk4;
    s32 unk8;
};

struct Obj {
    char pad[0x34];
    Inner unk34;
};

extern "C" s32 func_0022EFE8(Obj *arg0) {
    Inner *p = &arg0->unk34;
    return p->unk4 != p->unk8;
}
