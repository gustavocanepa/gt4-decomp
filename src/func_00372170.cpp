typedef int s32;

struct Elem {
    char pad[0x1A0];
    s32 unk1A0;
};

struct Obj {
    char pad[0x9BC];
    s32 unk9BC;
};

extern "C" void func_00372170(Obj *arg0) {
    ((Elem *)((char *)arg0 + arg0->unk9BC * 0x19C))->unk1A0 = 2;
}
