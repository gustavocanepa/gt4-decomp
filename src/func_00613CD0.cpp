typedef int s32;

struct Obj {
    char pad4[4];
    s32 unk4;
    char pad8[4];
    s32 unkC;
    s32 unk10;
};

extern "C" s32 func_00613CD0(Obj *arg0) {
    s32 b = arg0->unk10;
    s32 a = arg0->unk4;
    s32 c = arg0->unkC;
    return c + (a * b);
}
