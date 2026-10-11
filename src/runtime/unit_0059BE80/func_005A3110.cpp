typedef int s32;

extern s32 _impure_ptr;
extern "C" s32 func_00575F90(s32 arg0, s32 arg1);

extern "C" s32 func_005A3110(s32 arg0) {
    return func_00575F90(_impure_ptr, arg0);
}
