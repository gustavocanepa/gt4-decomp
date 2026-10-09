typedef int s32;

extern "C" void func_00501870(s32 arg0, s32 arg1);
extern "C" s32 func_005030C8(void);

extern "C" void func_00503358(s32 arg0) {
    s32 v0 = func_005030C8();
    if (v0 != 0) {
        func_00501870(v0, arg0);
    }
}
