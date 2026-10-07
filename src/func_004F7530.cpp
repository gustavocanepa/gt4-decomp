typedef int s32;

extern "C" s32 func_00509568(s32 arg0, s32 arg1, void *arg2);

extern "C" s32 func_004F7530(s32 arg0, s32 arg1, s32 arg2) {
    s32 local;
    return func_00509568(arg1, arg2, &local) == 0;
}
