typedef int s32;

extern "C" void func_0022AD20(s32 *arg0);
extern "C" void func_0028E3D0(s32 *arg0, s32 arg1);
extern "C" void func_002319A0(s32 arg0, s32 *arg1);
extern "C" void func_0028E378(s32 *arg0, s32 arg1);
extern "C" void func_0022ACC8(s32 *arg0, s32 arg1);

extern "C" void func_0022B9F0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg2 == 1) {
        s32 buf0[4];
        s32 buf1[4];

        func_0022AD20(buf0);
        func_0028E3D0(buf1, arg3);
        func_002319A0(buf0[0], buf1);
        func_0028E378(buf1, 2);
        func_0022ACC8(buf0, 2);
    }
}
