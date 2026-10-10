typedef int s32;

struct Obj {
    char pad[0x10];
    s32 unk10;
    s32 unk14;
    s32 unk18;
};

extern "C" void mTransition__panOut(Obj *arg0) {
    arg0->unk18 = 0;
    arg0->unk10 = 1;
    arg0->unk14 = 0;
}
