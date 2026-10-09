typedef int s32;
typedef signed char s8;

extern "C" s32 func_00593620(s32 arg0, s32 arg1, s32 arg2, s8 arg3);

extern "C" s32 func_006146A8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    return func_00593620(arg0, arg1, arg2, (s8)arg3);
}
