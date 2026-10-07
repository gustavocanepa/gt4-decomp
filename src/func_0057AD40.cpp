typedef int s32;
typedef signed char s8;

struct Obj {
    s32 unk0;
    s32 unk4;
    s8 unk8;
    char pad9[0xC - 9];
    s32 unkC;
};

extern "C" void func_0057AD40(Obj *arg0) {
    s32 temp_v0 = arg0->unk0;
    arg0->unk8 = 0;
    arg0->unk4 = temp_v0;
    arg0->unkC = 0;
}
