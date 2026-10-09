typedef int s32;

struct Obj {
    char pad[0x490];
    s32 unk490;
};

extern "C" s32 func_00441260(Obj *arg0, s32 arg1);

extern "C" s32 func_00441280(Obj *arg0)
{
    return func_00441260(arg0, arg0->unk490);
}
