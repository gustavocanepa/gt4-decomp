typedef int s32;

extern char D_004D7050;

struct Obj004D91D8 {
    s32 unk0;
    char pad4[0xC - 0x0 - 4];
    s32 unkC;
    s32 unk10;
    s32 unk14;
};

extern "C" void func_004D91D8(struct Obj004D91D8 *arg0) {
    arg0->unk0 = (s32)&D_004D7050;
    arg0->unk10 = 1;
    arg0->unkC = 0;
    arg0->unk14 = 0;
}
