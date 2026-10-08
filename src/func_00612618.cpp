typedef int s32;

struct Obj {
    char pad[0xC4];
    s32 unkC4;
};

extern "C" s32 func_0055EF50(s32 arg0);

extern "C" s32 func_00612618(Obj *arg0) {
    return func_0055EF50(arg0->unkC4);
}
