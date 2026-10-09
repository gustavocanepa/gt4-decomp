typedef int s32;

struct Obj {
    char pad0[0xAC];
    s32 unkAC;
};

extern "C" s32 func_004AE9E8(s32 arg0);

extern "C" s32 func_004B0A38(Obj *arg0) {
    return func_004AE9E8(arg0->unkAC);
}
