typedef int s32;

struct Buf {
    s32 unk0;
    s32 unk4;
    void *data;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
};

extern "C" void func_00575DA0(void *p);

extern "C" void func_004720B8(Buf *b) {
    if (b->data)
        func_00575DA0(b->data);
    b->unk0 = 0;
    b->unk4 = 0;
    b->data = 0;
    b->unkC = 0;
    b->unk10 = 0;
    b->unk14 = 0;
    b->unk1C = 0;
    b->unk18 = 0;
}
