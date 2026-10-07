typedef int s32;

extern "C" void func_00211460(s32 *arg0);
extern "C" void func_00204D88(s32 *arg0, s32 arg1);
extern "C" void func_00212ED0(s32 arg0, s32 *arg1);
extern "C" void func_00204D30(s32 *arg0, s32 arg1);
extern "C" void func_00211408(s32 *arg0, s32 arg1);

extern "C" void func_002118E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg2 == 1) {
        s32 buf0[4];
        s32 buf1[4];

        func_00211460(buf0);
        func_00204D88(buf1, arg3);
        func_00212ED0(buf0[0], buf1);
        func_00204D30(buf1, 2);
        func_00211408(buf0, 2);
    }
}
