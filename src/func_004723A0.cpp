typedef int s32;

extern "C" s32 func_00472400(s32 arg0);
extern "C" s32 func_00472408(s32 arg0, s32 arg1);

extern "C" s32 func_004723A0(s32 arg0)
{
    s32 s0 = arg0;
    s32 v0 = func_00472400(arg0);
    return func_00472408(s0, v0);
}
