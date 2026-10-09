typedef int s32;

extern "C" void func_00576788(void *arg0);
extern "C" void func_005767C0(void *arg0);
extern "C" s32 func_0054AB88(s32 arg0, s32 arg1);

extern void *D_0064C3E4;

extern "C" s32 func_0054B630(s32 arg0, s32 arg1) {
    func_00576788((char *)D_0064C3E4 + 0x34);
    s32 result = func_0054AB88(arg0, arg1);
    func_005767C0((char *)D_0064C3E4 + 0x34);
    return result;
}
