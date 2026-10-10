typedef int s32;

extern "C" void func_004AE230(void *, s32, s32);
extern "C" void func_00498B28(s32);

extern "C" s32 func_00103B40(s32 arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 v;
    func_004AE230(buf0, arg0, 1);
    v = buf1[0];
    func_00498B28(v);
    return v;
}
