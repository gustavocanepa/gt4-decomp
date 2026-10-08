typedef int s32;

extern "C" void func_002FB190(s32 arg0, s32 *arg1);
extern "C" int func_0031B500(int arg0);

extern "C" void func_0031B580(s32 arg0) {
    s32 s0 = arg0;
    s32 local = func_0031B500(1);
    func_002FB190(s0, &local);
}
