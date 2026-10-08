typedef int s32;
typedef unsigned short u16;

struct Obj {
    char pad0[0x48];
    u16 unk48;
    char pad1[0x144 - 0x4A];
    s32 unk144;
};

extern "C" s32 func_001D0538(Obj *arg0) {
    if ((arg0->unk48 & 1) == 0) {
        return 0;
    }
    return arg0->unk144;
}
