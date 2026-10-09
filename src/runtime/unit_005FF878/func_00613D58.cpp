typedef int s32;

struct Obj {
    s32 unk0;
    char pad8[8];
    s32 unkC;
    s32 unk10;
};

extern "C" s32 func_00613D58(Obj *arg0) {
    s32 b = arg0->unk10;
    s32 a = arg0->unk0;
    s32 c = arg0->unkC;
    return c + (a * b);
}
