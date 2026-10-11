typedef int s32;

extern s32 _impure_ptr;

extern "C" s32 func_005AC358(s32 arg0, s32 arg1, s32 arg2);

extern "C" s32 func_005AC3F8(s32 arg0, s32 arg1) {
    return func_005AC358(_impure_ptr, arg0, arg1);
}
