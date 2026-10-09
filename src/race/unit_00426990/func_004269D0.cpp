typedef int s32;

extern "C" s32 func_00426A38(s32 arg0);

extern "C" s32 func_004269D0(s32 arg0, s32 arg1)
{
    s32 s0 = arg1;
    return (func_00426A38(arg0) & s0) != 0;
}
