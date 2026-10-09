typedef int s32;

struct Inner {
    s32 unkNeg10;
};

struct Obj {
    char pad[0x10];
    Inner *unk10;
};

extern "C" s32 func_00314B10(Obj *arg0) {
    return *(s32 *)((char *)arg0->unk10 - 0x10);
}
