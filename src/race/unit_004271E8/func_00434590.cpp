typedef int s32;

struct Obj {
    s32 unk0;
    char unk4;
    char pad5[0x24 - 0x5];
    char unk24;
    char pad25[0x44 - 0x25];
    s32 unk44;
    s32 unk48;
    s32 unk4C;
    s32 unk50;
    s32 unk54;
    s32 unk58;
    s32 unk5C;
    s32 unk60;
    s32 unk64;
    s32 unk68;
    s32 unk6C;
};

extern "C" void func_00434590(Obj *p) {
    p->unk44 = 0x5A;
    p->unk50 = 4;
    p->unk58 = 3;
    p->unk0 = 0;
    p->unk48 = 0;
    p->unk4C = 0;
    p->unk54 = 0;
    p->unk5C = 0;
    p->unk60 = 0;
    p->unk64 = 0;
    p->unk68 = 0;
    p->unk6C = 0;
    p->unk4 = 0;
    p->unk24 = 0;
}
