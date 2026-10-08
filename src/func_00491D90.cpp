typedef int s32;

extern "C" s32 func_004AE230(s32 arg0, s32 arg1, s32 arg2);

extern "C" s32 func_00491D90(s32 arg0) {
    s32 buf[8];
    func_004AE230((s32)buf, arg0, 1);
    return buf[4];
}
