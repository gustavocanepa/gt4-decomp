typedef int s32;
typedef unsigned int u32;

struct Obj {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    u32 unk1C;
};

extern "C" void func_003A9608(struct Obj *arg0) {
    arg0->unk18 = -1;
    arg0->unk1C = arg0->unk1C & ~0xFF;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
    arg0->unkC = 0;
    arg0->unk10 = 0;
    arg0->unk14 = 0;
    arg0->unk0 = 0;
}
