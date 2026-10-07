typedef int s32;

struct Obj {
    char pad0[4];
    s32 unk4;
};

extern "C" s32 func_00427778(s32 arg0);

extern "C" s32 func_0042A0D0(Obj *arg0)
{
    return func_00427778(arg0->unk4);
}
