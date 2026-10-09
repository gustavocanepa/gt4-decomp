typedef int s32;

extern "C" void func_00576788(s32 arg0);
extern "C" void func_005767C0(s32 arg0);
extern "C" void func_0057CB80(s32 arg0, s32 arg1);

extern "C" void func_0055FAF8(s32 arg0, s32 arg1) {
    func_00576788(arg0);
    func_0057CB80(arg0 + 0x30, arg1 + 8);
    func_005767C0(arg0);
}
