typedef int s32;

extern "C" void func_00578908(s32 arg0);
extern "C" void func_00578AF0(s32 arg0);

extern s32 D_00619030;

extern "C" void func_00213C10(void) {
    func_00578908(D_00619030);
    func_00578AF0(D_00619030);
    D_00619030 = 0;
}
