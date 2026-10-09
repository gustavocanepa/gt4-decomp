typedef int s32;

extern "C" s32 func_004321F0();
extern "C" void func_0042E478(s32 arg0, s32 arg1, s32 arg2);

extern "C" void func_00432228(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_0042E478(func_004321F0(), arg2, arg3);
}
