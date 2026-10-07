typedef int s32;

extern "C" void func_0029CA40(s32 *arg0);
extern "C" void func_00312370(s32 *arg0, s32 arg1);
extern "C" void func_0029C7F8(s32 arg0, s32 *arg1);
extern "C" void func_00312318(s32 *arg0, s32 arg1);
extern "C" void func_0029C9E8(s32 *arg0, s32 arg1);

extern "C" void func_0029C1B8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg2 > 0) {
        s32 buf0[4];
        s32 buf1[4];

        func_0029CA40(buf0);
        func_00312370(buf1, arg3);
        func_0029C7F8(buf0[0], buf1);
        func_00312318(buf1, 2);
        func_0029C9E8(buf0, 2);
    }
}
