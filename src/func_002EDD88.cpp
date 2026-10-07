typedef int s32;

extern "C" void func_002ED5C0(void *arg0, s32 arg1);
extern "C" void func_002ED618(void *arg0);
extern "C" void func_002EED68(s32 *arg0, s32 arg1);
extern "C" void func_00309378(s32 *arg0, s32 arg1);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);

extern "C" void func_002EDD88(s32 *arg0) {
    s32 sp[4];
    s32 sp10[4];
    s32 *p1;
    s32 temp_a0;
    s32 temp_s0;

    func_002ED618(sp);
    p1 = sp10;
    func_002EED68(p1, sp[0]);
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
    func_00309378(p1, 2);
    func_002ED5C0(sp, 2);
}
