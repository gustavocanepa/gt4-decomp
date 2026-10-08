typedef int s32;
typedef unsigned short u16;

struct Elem {
    s32 val;
    s32 pad4;
};

struct Obj {
    char pad0[0x38];
    u16 unk38;
    char pad1[0x1E];
    struct Elem *unk58;
};

extern "C" s32 func_003E6BF0(struct Obj *arg0, s32 arg1) {
    if (arg1 < arg0->unk38) {
        return arg0->unk58[arg1].val;
    }
    return 0;
}
