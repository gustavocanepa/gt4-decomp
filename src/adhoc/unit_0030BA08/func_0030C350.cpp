typedef int s32;
typedef void (*FnVoid)(void);

extern "C" void func_0030C348(void);

extern FnVoid D_00619DF8;

extern "C" void func_0030C350(s32 arg0) {
    if (arg0 != 0) {
        D_00619DF8 = (FnVoid)arg0;
        return;
    }
    D_00619DF8 = func_0030C348;
}
