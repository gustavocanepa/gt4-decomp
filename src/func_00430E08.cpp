typedef int s32;

extern "C" s32 func_00430E38(s32 arg0, s32 arg1);
extern "C" s32 func_004483B8(s32 arg0);

extern "C" s32 func_00430E08(s32 arg0, s32 arg1) {
    return func_00430E38(arg0, func_004483B8(arg1));
}
