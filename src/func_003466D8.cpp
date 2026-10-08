typedef int s32;

extern "C" s32 func_003466B8(s32 arg0);

extern "C" s32 func_003466D8(s32 arg0, s32 arg1) {
    return func_003466B8(arg0) + (arg1 << 16);
}
