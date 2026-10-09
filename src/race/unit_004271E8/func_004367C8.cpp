typedef int s32;

struct Obj {
    char pad0[0xC];
    s32 unkC;
};

extern "C" s32 func_0048EDA0(s32 arg0);

extern "C" s32 func_004367C8(Obj *arg0)
{
    return func_0048EDA0(arg0->unkC);
}
