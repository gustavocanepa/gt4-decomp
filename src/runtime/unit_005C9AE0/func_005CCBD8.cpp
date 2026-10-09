typedef int s32;

struct Inner {
    char pad[0x1140];
    s32 unk1140;
};

struct Obj {
    char pad[0x10];
    Inner *unk10;
};

extern "C" s32 func_005CCBD8(Obj *arg0) {
    s32 r = 0;
    if (arg0->unk10->unk1140 & 0x200) {
        r = 1;
    }
    return r;
}
