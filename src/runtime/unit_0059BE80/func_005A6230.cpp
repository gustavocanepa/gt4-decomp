typedef int s32;

extern s32 _impure_ptr;
extern "C" s32 func_005A6250(s32 arg0, s32 arg1);

extern "C" s32 func_005A6230(s32 arg0) {
    return func_005A6250(_impure_ptr, arg0);
}
