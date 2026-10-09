typedef int s32;

extern "C" s32 func_002DB0D8(s32 arg0, s32 arg1);
extern "C" void func_00255088(s32 arg0, s32 *arg1);

extern "C" s32 func_002DB478(s32 arg0, s32 arg1, s32 arg2) {
    s32 resultLocal;
    s32 zeroLocal;
    s32 result = func_002DB0D8(arg1, arg2);

    if (result != 0) {
        resultLocal = result;
        func_00255088(arg0, &resultLocal);
    } else {
        zeroLocal = 0;
        func_00255088(arg0, &zeroLocal);
    }

    return arg0;
}
