typedef int s32;

extern char fflush[];
extern "C" s32 func_005A43A8(s32 arg0, char *arg1);

extern "C" s32 func_005A3628(s32 arg0) {
    return func_005A43A8(arg0, fflush);
}
