typedef int s32;

struct Obj {
    s32 unk0;
    char pad[0x14];
    s32 unk18;
};

extern "C" void AutomaticFader__reset(Obj *arg0) {
    arg0->unk0 = 0;
    arg0->unk18 = 2;
}
