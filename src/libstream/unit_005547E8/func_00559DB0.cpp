extern int D_006504F8;
extern char SDDRV__VoiceSystem__master_[];

extern "C" void func_0055E5C8(void);
extern "C" void func_0055C5F0(void *p, float rate);
extern "C" void func_0055D380(void);
extern "C" void func_0055C2A8(void);
extern "C" void func_0055A4D8(void);
extern "C" void func_00559790(void);
extern "C" void func_0055EC60(void);

extern "C" void func_00559DB0(void) {
    int *initialized = &D_006504F8;
    if (*initialized)
        return;
    *initialized = 1;
    func_0055E5C8();
    func_0055C5F0(SDDRV__VoiceSystem__master_, 60.0f);
    func_0055D380();
    func_0055C2A8();
    func_0055A4D8();
    func_00559790();
    func_0055EC60();
}
