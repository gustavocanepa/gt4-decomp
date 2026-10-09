typedef int s32;

struct Elem {
    char pad[0x118];
    s32 unk118;
};

struct Obj {
    char pad[0x2DC];
    s32 unk2DC;
};

extern "C" s32 func_0045ACE0(Obj *arg0) {
    return ((Elem *)((char *)arg0 + arg0->unk2DC * 0x16C))->unk118;
}
