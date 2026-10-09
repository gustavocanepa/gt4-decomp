typedef int s32;
typedef float f32;

extern "C" void func_002E1FE0(void *arg0, s32 arg1);
extern "C" void func_002E2038(void *arg0);
extern "C" f32 func_002E2838(s32 arg0);
extern "C" void func_002F7B68(s32 *arg0, s32 arg1);
extern "C" void func_002F9360(s32 *arg0, f32 arg1);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);

extern "C" void MSwitchActor__get_period(s32 *arg0) {
    s32 sp[4];
    s32 sp10[4];
    s32 *p1;
    s32 temp_a0;
    s32 temp_s0;

    func_002E2038(sp);
    {
        f32 t = func_002E2838(sp[0]);
        p1 = sp10;
        func_002F9360(p1, t);
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
    func_002F7B68(p1, 2);
    func_002E1FE0(sp, 2);
}
