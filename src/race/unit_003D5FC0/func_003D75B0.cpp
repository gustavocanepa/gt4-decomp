typedef int s32;

struct Obj {
    char pad0[4];
    s32 unk4;
};

extern "C" s32 func_00344A70(s32 arg0);

extern "C" s32 func_003D75B0(Obj *arg0)
{
    return func_00344A70(arg0->unk4);
}
