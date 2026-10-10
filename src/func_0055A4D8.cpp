typedef int s32;

typedef void (*Fn)(void);
extern Fn D_00651954;
extern "C" void func_0055A520(s32, s32);
extern "C" void func_00568060(s32, void (*)(void), s32);
extern "C" void func_0055A498(void);
extern "C" void func_0055A4B8(void);

extern "C" void func_0055A4D8(void) {
    func_0055A520(0x3FFF, 0);
    Fn f = func_0055A498;
    D_00651954 = f;
    func_00568060(0, func_0055A4B8, 0);
}
