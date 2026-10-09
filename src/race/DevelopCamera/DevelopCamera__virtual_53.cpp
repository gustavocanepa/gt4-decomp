typedef int s32;
typedef unsigned int u32;

struct Elem {
    char pad[0x148];
    s32 unk148;
};

struct Obj {
    char pad[0x9BC];
    s32 unk9BC;
};

extern "C" s32 DevelopCamera__virtual_53(Obj *arg0) {
    return ((Elem *)((char *)arg0 + arg0->unk9BC * 0x19C))->unk148 == 0;
}
