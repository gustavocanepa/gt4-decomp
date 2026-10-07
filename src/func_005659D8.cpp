typedef int s32;

extern char D_00689C68;

struct Obj {
    char pad0[0x14];
    s32 unk14;
    char pad18[0x18 - 0x14 - 4];
    s32 unk18;
    char pad1C[0x68 - 0x18 - 4];
    s32 unk68;
};

extern "C" void func_005659D8(Obj *arg0) {
    arg0->unk18 = -1;
    arg0->unk68 = (s32)&D_00689C68;
    arg0->unk14 = 0;
}
