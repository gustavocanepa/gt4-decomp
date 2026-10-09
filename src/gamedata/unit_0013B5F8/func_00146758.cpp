typedef int s32;

struct S;

extern "C" s32 func_00147D80(S *arg0);
extern "C" s32 func_00441248(s32 arg0);
extern "C" s32 func_00445650(s32 arg0);

extern "C" s32 func_00146758(S *arg0)
{
    s32 v0 = func_00147D80(arg0);
    v0 = func_00441248(v0);
    return func_00445650(v0);
}
