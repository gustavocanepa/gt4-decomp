typedef int s32;
typedef short s16;

struct Elem {
    char pad[0x1C];
    s16 unk1C;
};

struct Obj {
    char pad[0x9BC];
    s32 unk9BC;
};

extern "C" s16 func_005F5400(Obj *arg0) {
    return ((Elem *)((char *)arg0 + arg0->unk9BC * 0x19C))->unk1C;
}
