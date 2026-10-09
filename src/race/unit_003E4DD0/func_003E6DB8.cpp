typedef int s32;
typedef unsigned short u16;

struct Elem {
    s32 val;
    s32 pad4;
};

struct Obj {
    char pad0[0x8];
    u16 unk8;
    char pad1[0xA];
    struct Elem *unk14;
};

extern "C" s32 func_003E6DB8(struct Obj *arg0, s32 arg1) {
    if (arg1 < arg0->unk8) {
        return arg0->unk14[arg1].val;
    }
    return 0;
}
