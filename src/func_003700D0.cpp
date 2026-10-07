typedef int s32;

extern "C" void func_00370070(void);
extern "C" void func_003700B0(void);

extern "C" void func_003700D0(void *arg0, s32 arg1) {
    if (arg1 != 0) {
        return func_00370070();
    }
    return func_003700B0();
}
