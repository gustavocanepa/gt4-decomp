typedef int s32;

struct Obj {
    char pad0[4];
    s32 unk4;
};

extern "C" s32 func_004501D0(s32 arg0);

extern "C" s32 func_00604010(Obj *arg0)
{
    return func_004501D0(arg0->unk4);
}
