typedef int s32;

struct Obj003FF750 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
};

extern "C" void func_003FF750(struct Obj003FF750 *arg0, s32 arg1, s32 arg2) {
    arg0->unk8 = arg1;
    arg0->unk0 = arg2;
    arg0->unkC = 2;
    arg0->unk4 = 0;
    arg0->unk10 = 0;
}
