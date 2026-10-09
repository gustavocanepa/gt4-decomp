typedef int s32;

struct Obj {
    char pad0[4];
    s32 unk4;
    char pad1[4];
    s32 unkC;
    char pad2[4];
    s32 unk14;
};

extern "C" s32 func_00471F70(Obj *arg0) {
    s32 a = arg0->unk4;
    s32 b = arg0->unkC;
    s32 c = arg0->unk14;
    s32 v0 = (b < a) ? b : a;
    return (c < v0) ? c : v0;
}
