typedef int s32;

extern "C" s32 func_00430F70(s32 arg0, s32 arg1);
extern "C" s32 func_004483B8(s32 arg0);

extern "C" s32 func_00430F40(s32 arg0, s32 arg1) {
    return func_00430F70(arg0, func_004483B8(arg1));
}
