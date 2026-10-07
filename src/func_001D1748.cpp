typedef int s32;

struct Obj {
    char pad0[4];
    s32 unk4;
};

extern "C" s32 func_0054A740(s32 arg0);

extern "C" s32 func_001D1748(Obj *arg0)
{
    return func_0054A740(arg0->unk4);
}
