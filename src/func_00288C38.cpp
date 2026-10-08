typedef int s32;

struct Inner {
    char pad[0x4];
    s32 unk4;
    s32 unk8;
};

struct Obj {
    char pad[0xB0];
    Inner unkB0;
};

extern "C" s32 func_00288C38(Obj *arg0) {
    Inner *p = &arg0->unkB0;
    return (s32)(p->unk8 - p->unk4) >> 4;
}
