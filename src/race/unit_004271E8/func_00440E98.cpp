typedef int s32;

extern "C" s32 func_00440EC8(s32 arg0, s32 arg1);
extern "C" s32 func_00447BB8(s32 arg0);

extern "C" s32 func_00440E98(s32 arg0, s32 arg1) {
    return func_00440EC8(arg0, func_00447BB8(arg1));
}
