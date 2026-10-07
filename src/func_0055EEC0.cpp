typedef int s32;

extern "C" void func_00576788(s32 arg0);
extern "C" void func_005767C0(s32 arg0);
extern "C" void func_0057CB00(s32 arg0, s32 arg1);

extern "C" void func_0055EEC0(s32 arg0, s32 arg1) {
    func_00576788(arg0);
    func_0057CB00(arg0 + 0x40, arg1 + 8);
    func_005767C0(arg0);
}
