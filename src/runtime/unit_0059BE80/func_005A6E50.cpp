typedef int s32;

extern "C" s32 _impure_ptr;
extern "C" s32 func_005A6E70(s32 arg0, s32 arg1, s32 arg2);

extern "C" s32 func_005A6E50(s32 arg0, s32 arg1) {
    return func_005A6E70(arg0, arg1, _impure_ptr + 0x5C);
}
