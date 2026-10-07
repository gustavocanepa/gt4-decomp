typedef int s32;

extern "C" void func_00123838(s32 *arg0);
extern "C" void func_001298C8(s32 *arg0, s32 arg1);
extern "C" void func_0011FF98(s32 arg0, s32 *arg1);
extern "C" void func_00129870(s32 *arg0, s32 arg1);
extern "C" void func_001237E0(s32 *arg0, s32 arg1);

extern "C" void func_0011F180(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg2 > 0) {
        s32 buf0[4];
        s32 buf1[4];

        func_00123838(buf0);
        func_001298C8(buf1, arg3);
        func_0011FF98(buf0[0], buf1);
        func_00129870(buf1, 2);
        func_001237E0(buf0, 2);
    }
}
