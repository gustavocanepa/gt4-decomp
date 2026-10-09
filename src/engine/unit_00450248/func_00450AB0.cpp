typedef int s32;

extern "C" void func_004583D0(s32 arg0);

extern "C" void func_00450AB0(s32 *arg0, s32 arg1) {
    *arg0 = arg1;
    func_004583D0(arg1);
}
