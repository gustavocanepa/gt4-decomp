typedef int s32;

extern "C" void func_00248C48(s32 *arg0);
extern "C" s32 func_00249EE0(s32 arg0);
extern "C" void func_00314B20(s32 *arg0, s32 arg1);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);
extern "C" void func_00312318(s32 *arg0, s32 arg1);
extern "C" void func_00248BF0(s32 *arg0, s32 arg1);

extern "C" void MToolTipFace__get_value(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p1 = buf1;
    s32 newVal;
    s32 oldVal;

    func_00248C48(p1);
    func_00314B20(buf0, func_00249EE0(*p1));
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
    func_00248BF0(p1, 2);
}
