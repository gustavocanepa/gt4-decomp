typedef int s32;

extern "C" void func_001DC5F8(void *arg0, s32 arg1);
extern "C" void func_001DC650(void *arg0);
extern "C" void func_001F13C0(s32 *arg0, s32 arg1);
extern "C" void func_00312318(s32 *arg0, s32 arg1);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);

extern "C" void func_001DDA08(s32 *arg0) {
    s32 sp[4];
    s32 sp10[4];
    s32 *p1;
    s32 temp_a0;
    s32 temp_s0;

    func_001DC650(sp);
    p1 = sp10;
    func_001F13C0(p1, sp[0]);
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
    func_001DC5F8(sp, 2);
}
