typedef int s32;

struct Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    char pad[0x1C - 0x8 - 4];
    s32 unk1C;
    char pad2[0x24 - 0x1C - 4];
    s32 unk24;
};

extern "C" void func_00551568(Obj *arg0) {
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
    arg0->unk1C = 0;
    arg0->unk24 = 0;
}
