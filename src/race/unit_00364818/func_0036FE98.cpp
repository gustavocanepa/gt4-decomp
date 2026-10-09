typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x8];
    f32 unk8;
    f32 unkC;
};

extern "C" f32 func_0036FE98(Obj *arg0, s32 arg1) {
    if (arg1 != 0) {
        return arg0->unk8;
    }
    return arg0->unkC;
}
