typedef int s32;

struct Elem {
    char pad[0x20];
    s32 unk20;
};

struct Obj {
    char pad[0x9BC];
    s32 unk9BC;
};

extern "C" s32 func_00373DC0(Obj *arg0) {
    return ((Elem *)((char *)arg0 + arg0->unk9BC * 0x19C))->unk20;
}
