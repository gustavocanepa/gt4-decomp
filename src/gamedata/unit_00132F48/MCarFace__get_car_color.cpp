typedef int s32;

extern "C" void func_00137DB8(s32 *arg0);
extern "C" s32 func_0013A960(s32 arg0);
extern "C" void func_002FE278(s32 *arg0, s32 arg1);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);
extern "C" void func_002FC870(s32 *arg0, s32 arg1);
extern "C" void func_00137D60(s32 *arg0, s32 arg1);

extern "C" void MCarFace__get_car_color(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p1 = buf1;
    s32 newVal;
    s32 oldVal;

    func_00137DB8(p1);
    func_002FE278(buf0, func_0013A960(*p1));
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
    func_002FC870(buf0, 2);
    func_00137D60(p1, 2);
}
