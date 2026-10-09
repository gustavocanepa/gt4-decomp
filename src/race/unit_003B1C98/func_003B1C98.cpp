typedef int s32;

extern "C" void func_003B0FD0(s32 arg0, s32 arg1);

extern "C" void func_003B1C98(s32 arg0, s32 *arg1) {
    func_003B0FD0(arg0, *arg1);
}
