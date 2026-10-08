typedef int s32;

extern "C" s32 func_004542D8(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);

extern "C" s32 func_00390038(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4)
{
    return func_004542D8(arg0 + 0x18, arg2, arg3, arg4, arg1);
}
