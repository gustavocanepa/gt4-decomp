typedef int s32;

extern "C" void func_002D5480(void *arg0, s32 arg1);
extern "C" void func_002D54D8(void *arg0);
extern "C" void func_002FC870(s32 *arg0, s32 arg1);
extern "C" void func_002FE278(s32 *arg0, s32 arg1);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);
extern "C" s32 func_0057CEC8(s32 arg0);

extern "C" void MSelectBar__incLimit(s32 *arg0) {
    s32 sp[4];
    s32 sp10[4];
    s32 *p1;
    s32 temp_a0;
    s32 temp_s0;

    func_002D54D8(sp);
    {
        s32 t = func_0057CEC8(sp[0] + 0xBC) != 0;
        p1 = sp10;
        func_002FE278(p1, t);
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
    func_002FC870(p1, 2);
    func_002D5480(sp, 2);
}
