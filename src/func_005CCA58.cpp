typedef int s32;

struct ObjInner {
    char pad[0x1140];
    s32 unk1140;
};

struct Obj {
    char pad[0x10];
    ObjInner *unk10;
};

extern "C" s32 func_005CCA58(Obj *arg0) {
    s32 r = 0;
    if (arg0->unk10->unk1140 & 8) {
        r = 1;
    }
    return r;
}
