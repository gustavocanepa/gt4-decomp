typedef int s32;

extern "C" s32 func_004F9E90(s32 arg0);
extern "C" s32 func_004F9B88(s32 arg0, s32 arg1);

extern "C" s32 func_004F9BA8(s32 arg0)
{
    s32 s0 = arg0;
    s32 v0 = func_004F9E90(arg0);
    return func_004F9B88(s0, v0);
}
