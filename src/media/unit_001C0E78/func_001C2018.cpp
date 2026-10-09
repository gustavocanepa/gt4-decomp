typedef int s32;

struct Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    char pad[0x10 - 0xC];
    s32 unk10;
    s32 unk14;
};

extern "C" void func_001C2018(Obj *arg0) {
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
    arg0->unk10 = 0;
    arg0->unk14 = 0;
}
