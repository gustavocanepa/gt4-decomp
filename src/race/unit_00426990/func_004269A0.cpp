typedef int s32;

extern "C" s32 func_00426A08(s32 arg0);

extern "C" s32 func_004269A0(s32 arg0, s32 arg1)
{
    s32 s0 = arg1;
    return (func_00426A08(arg0) & s0) != 0;
}
