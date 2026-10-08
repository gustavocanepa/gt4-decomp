typedef int s32;

struct Obj {
    char pad0[0x7B4];
    s32 unk7B4;
    s32 unk7B8;
    char pad1[0x7C4 - 0x7BC];
    s32 unk7C4;
    s32 unk7C8;
    s32 unk7CC;
    s32 unk7D0;
    s32 unk7D4;
    s32 unk7D8;
};

extern "C" void func_003B0ED8(Obj *arg0) {
    arg0->unk7B4 = 0;
    arg0->unk7B8 = 1;
    arg0->unk7C4 = 0;
    arg0->unk7C8 = 0;
    arg0->unk7CC = 0;
    arg0->unk7D0 = 0;
    arg0->unk7D4 = 0;
    arg0->unk7D8 = 0;
}
