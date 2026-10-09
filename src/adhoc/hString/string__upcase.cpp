typedef int s32;

extern "C" void func_00312370(s32 *arg0);
extern "C" void func_00314E38(s32 *arg0, s32 arg1);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);
extern "C" void func_00312318(s32 *arg0, s32 arg1);
extern "C" void func_00312318(s32 *arg0, s32 arg1);

extern "C" void string__upcase(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p1 = buf1;
    s32 newVal;
    s32 oldVal;

    func_00312370(p1);
    func_00314E38(buf0, *p1);
    if (arg0 != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *arg0 = newVal;
    }
    func_00312318(buf0, 2);
    func_00312318(p1, 2);
}
