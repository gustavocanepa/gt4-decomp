typedef int s32;
typedef float f32;

struct Obj {
    char pad0[4];
    s32 unk4;
    char pad1[0x6E8 - 4 - 4];
    f32 unk6E8;
};

extern "C" s32 func_0034C9D0(s32 arg0);

extern "C" f32 func_00344A70(struct Obj *arg0) {
    s32 r = func_0034C9D0(arg0->unk4);
    f32 v0 = 0.0f;

    if (r == 0) {
        v0 = arg0->unk6E8;
    }
    return v0;
}
