typedef int s32;

extern s32 _impure_ptr;
extern "C" s32 func_005A4B50(s32 arg0, s32 arg1);

extern "C" s32 func_005A4BD8(s32 arg0) {
    return func_005A4B50(_impure_ptr, arg0);
}
