typedef int s32;

struct Obj {
    char pad0[0x38];
    s32 unk38;
};

extern "C" s32 func_005AE388(s32 arg0);

extern "C" s32 func_0059B868(Obj *arg0) {
    return func_005AE388(arg0->unk38);
}
