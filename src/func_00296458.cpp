typedef int s32;

extern "C" void func_00295A80(void *arg0, s32 arg1);
extern "C" void func_00295AD8(void *arg0);
extern "C" s32 func_00296340(s32 arg0);
extern "C" void func_00312318(s32 *arg0, s32 arg1);
extern "C" void func_00314B20(s32 *arg0, s32 arg1);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);

extern "C" void func_00296458(s32 *arg0) {
    s32 sp[4];
    s32 sp10[4];
    s32 *p1;
    s32 temp_a0;
    s32 temp_s0;

    func_00295AD8(sp);
    {
        s32 t = func_00296340(sp[0]);
        p1 = sp10;
        func_00314B20(p1, t);
    }
    if (arg0 != p1) {
        temp_s0 = *p1;
        if (temp_s0 != 0) {
            func_003285A8(temp_s0);
        }
        temp_a0 = *arg0;
        if (temp_a0 != 0) {
            func_003285F8(temp_a0);
        }
        *arg0 = temp_s0;
    }
    func_00312318(p1, 2);
    func_00295A80(sp, 2);
}
