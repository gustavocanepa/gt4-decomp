typedef int s32;

extern "C" void func_0036FF38(void);
extern "C" void func_0036FF78(void);

extern "C" void func_0036FF98(void *arg0, s32 arg1) {
    if (arg1 != 0) {
        return func_0036FF38();
    }
    return func_0036FF78();
}
