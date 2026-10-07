typedef int s32;

struct Obj {
    char pad0[8];
    s32 unk8;
};

extern "C" s32 func_004501F0(s32 arg0);

extern "C" s32 func_00604058(Obj *arg0)
{
    return func_004501F0(arg0->unk8);
}
