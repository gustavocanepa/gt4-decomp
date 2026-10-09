typedef int s32;

struct Elem {
    char pad0[4];
    s32 unk4;
    char pad8[0x68];
};

struct Obj {
    char pad[0x44];
    Elem *unk44;
};

extern "C" s32 func_004EE678(struct Obj *arg0, s32 arg1) {
    return arg0->unk44[arg1].unk4;
}
