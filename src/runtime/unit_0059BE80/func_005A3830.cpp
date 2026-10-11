typedef int s32;

extern s32 _impure_ptr;

extern "C" s32 func_005A3750(s32 arg0, s32 arg1, s32 arg2);

extern "C" s32 func_005A3830(s32 arg0, s32 arg1) {
    return func_005A3750(_impure_ptr, arg0, arg1);
}
