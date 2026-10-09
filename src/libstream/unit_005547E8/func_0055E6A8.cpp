typedef int s32;

extern "C" s32 func_0055E678(s32 arg0, s32 arg1);

extern "C" s32 func_0055E6A8(s32 arg0)
{
    s32 cond = arg0 >= 0x18;
    return func_0055E678(cond, cond ? arg0 - 0x18 : arg0);
}
