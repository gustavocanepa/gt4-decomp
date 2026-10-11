typedef int s32;

extern "C" s32 memmove(s32 arg0, s32 arg1);

extern "C" s32 func_005A2FE8(s32 arg0, s32 arg1) {
    return memmove(arg1, arg0);
}
