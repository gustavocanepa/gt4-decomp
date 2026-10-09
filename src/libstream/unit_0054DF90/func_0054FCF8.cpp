typedef int s32;

struct Obj {
    char pad0[0xC];
    s32 unkC;
};

extern "C" s32 func_005647F0(s32 arg0);

extern "C" s32 func_0054FCF8(Obj *arg0)
{
    return func_005647F0(arg0->unkC);
}
