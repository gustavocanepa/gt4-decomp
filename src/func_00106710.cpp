typedef int s32;

extern "C" void func_00106748(s32 arg0);
extern "C" void func_00106258(s32 arg0, s32 arg1, s32 arg2);

extern "C" void func_00106710(s32 arg0) {
    s32 s0 = arg0;
    func_00106748(arg0);
    func_00106258(s0, 0x200, 0x1C0);
}
