typedef int s32;

extern "C" s32 func_00448528(s32 *arg0);
extern "C" void func_002FE278(s32 *arg0, s32 arg1);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);
extern "C" void func_002FC870(s32 *arg0, s32 arg1);

extern "C" void MCarData__GetCarLabelCount(s32 *arg0) {
    s32 buf[4];
    s32 temp_v0;

    func_002FE278(buf, func_00448528(arg0));
    if (arg0 != buf) {
        s32 s0 = buf[0];
        if (s0 != 0) {
            func_003285A8(s0);
        }
        temp_v0 = *arg0;
        if (temp_v0 != 0) {
            func_003285F8(temp_v0);
        }
        *arg0 = s0;
    }
    func_002FC870(buf, 2);
}
