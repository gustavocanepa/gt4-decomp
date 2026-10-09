typedef int s32;

extern "C" void func_00105440(s32 arg0);
extern "C" void func_00105450(s32 arg0, s32 arg2);

extern "C" void func_00105460(s32 arg0, s32 arg1, s32 arg2) {
    func_00105440(arg0);
    func_00105450(arg0, arg2);
}
