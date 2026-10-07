typedef int s32;
typedef signed char s8;

extern "C" s32 func_005937A0(s32 arg0, s32 arg1, s32 arg2, s8 arg3);

extern "C" s32 func_00614670(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return func_005937A0(arg0, arg1, arg2, (s8)arg3);
}
