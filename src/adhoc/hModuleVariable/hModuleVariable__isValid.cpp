typedef int s32;

extern "C" s32 HValue__isValid(s32 arg0);

extern "C" s32 hModuleVariable__isValid(s32 arg0) {
    return HValue__isValid(arg0 + 0x18);
}
