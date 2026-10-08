typedef int s32;

struct Obj001C20D8 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    char pad0[0x10 - 0x8 - 4];
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    char pad1[0x34 - 0x1C - 4];
    s32 unk34;
    s32 unk38;
    s32 unk3C;
    s32 unk40;
    s32 unk44;
    s32 unk48;
};

extern "C" void func_001C20D8(struct Obj001C20D8 *arg0) {
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    arg0->unk8 = 0;
    arg0->unk10 = 0;
    arg0->unk14 = 0;
    arg0->unk18 = 0;
    arg0->unk1C = 0;
    arg0->unk34 = 0;
    arg0->unk38 = 0;
    arg0->unk3C = 0;
    arg0->unk40 = 0;
    arg0->unk44 = 0;
    arg0->unk48 = 0;
}
