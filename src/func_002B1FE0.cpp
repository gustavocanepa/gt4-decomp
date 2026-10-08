typedef int s32;
typedef float f32;

struct Obj {
    char pad0[0xB0];
    s32 unkB0;
    char pad1[0xC0 - 0xB0 - 4];
    f32 unkC0;
    f32 unkC4;
};

extern "C" f32 func_002B1FE0(struct Obj *arg0) {
    if (arg0->unkB0 == 0) {
        return arg0->unkC0;
    }
    return arg0->unkC4;
}
