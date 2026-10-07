typedef int s32;

struct Elem {
    char pad1A4[0x1A4];
    s32 unk1A4;
    char pad1A8[0x1A8 - 0x1A4 - 4];
    s32 unk1A8;
};

struct Obj {
    char pad[0x9BC];
    s32 unk9BC;
};

extern "C" void func_003721B0(Obj *arg0, s32 arg1, s32 arg2) {
    ((Elem *)((char *)arg0 + arg0->unk9BC * 0x19C))->unk1A4 = arg1;
    ((Elem *)((char *)arg0 + arg0->unk9BC * 0x19C))->unk1A8 = arg2;
}
