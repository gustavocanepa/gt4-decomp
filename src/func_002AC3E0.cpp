typedef int s32;

extern "C" void func_002AC020(s32 *arg0);
extern "C" void func_002A5E18(s32 *arg0, s32 arg1);
extern "C" void func_002AC440(s32 arg0, s32 *arg1);
extern "C" void func_002A5DC0(s32 *arg0, s32 arg1);
extern "C" void func_002ABFC8(s32 *arg0, s32 arg1);

extern "C" void func_002AC3E0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    if (arg2 > 0) {
        s32 buf0[4];
        s32 buf1[4];

        func_002AC020(buf0);
        func_002A5E18(buf1, arg3);
        func_002AC440(buf0[0], buf1);
        func_002A5DC0(buf1, 2);
        func_002ABFC8(buf0, 2);
    }
}
