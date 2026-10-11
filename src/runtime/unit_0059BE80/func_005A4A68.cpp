typedef int s32;

extern s32 _impure_ptr;
extern "C" s32 func_005A49F8(s32 arg0, s32 arg1);

extern "C" s32 func_005A4A68(s32 arg0) {
    return func_005A49F8(_impure_ptr, arg0);
}
