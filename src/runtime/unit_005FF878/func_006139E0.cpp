typedef int s32;

extern "C" void func_005790B0(s32 *arg0, s32 arg1, s32 arg2);

extern "C" void func_006139E0(s32 *arg0, s32 arg1) {
    func_005790B0(arg0, *arg0, arg1);
}
