typedef int s32;

struct Obj {
    char pad0[8];
    s32 unk8;
};

extern "C" s32 func_0046BC40(s32 arg0);

extern "C" s32 func_0046BC98(Obj *arg0)
{
    return func_0046BC40(arg0->unk8);
}
