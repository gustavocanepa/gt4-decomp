typedef int s32;

struct Obj1D1880 {
    char pad[4];
    s32 unk4;
};

extern "C" s32 func_0054BC50(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern "C" s32 func_001D1880(Obj1D1880 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return func_0054BC50(arg0->unk4, arg1, arg2, arg4, arg3);
}
