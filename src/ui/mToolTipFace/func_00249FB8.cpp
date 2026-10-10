typedef int s32;

extern "C" void func_00235E68(s32 arg0, s32 arg1);
extern "C" s32 mWidget__getRootWindow(void);

extern "C" void func_00249FB8(s32 arg0) {
    s32 v0 = mWidget__getRootWindow();
    if (v0 != 0) {
        func_00235E68(v0, arg0);
    }
}
