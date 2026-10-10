typedef int s32;

struct Obj {
    char unk0;
    char pad1[0x3F];
    s32 unk40;
    s32 unk44;
    char pad48[0xC];
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    s32 unk60;
    s32 unk64;
};

extern "C" s32 func_005B72A8(void);

extern "C" void func_00549808(Obj *p) {
    s32 enabled = func_005B72A8();
    p->unk0 = 0;
    p->unk40 = 0;
    p->unk44 = 0;
    p->unk54 = 0;
    p->unk58 = 0;
    p->unk5C = 0;
    p->unk60 = 0;
    p->unk64 = 0;
    if (enabled)
        __asm__ volatile("ei");
}
