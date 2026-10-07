typedef int s32;

extern "C" void func_003228E0(s32 *arg0);
extern "C" void func_00318590(s32 *arg0, s32 arg1);
extern "C" void func_00323088(s32 arg0, s32 *arg1);
extern "C" void func_00318538(s32 *arg0, s32 arg1);
extern "C" void func_00322888(s32 *arg0, s32 arg1);

extern "C" void func_00322A30(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg2 == 1) {
        s32 buf0[4];
        s32 buf1[4];

        func_003228E0(buf0);
        func_00318590(buf1, arg3);
        func_00323088(buf0[0], buf1);
        func_00318538(buf1, 2);
        func_00322888(buf0, 2);
    }
}
