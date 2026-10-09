typedef int s32;

struct Obj {
    char pad0[0xC8];
    s32 unkC8;
};

extern "C" s32 func_0055EFC8(s32 arg0);

extern "C" s32 func_00612630(Obj *arg0) {
    return func_0055EFC8(arg0->unkC8);
}
