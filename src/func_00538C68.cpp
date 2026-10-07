typedef int s32;

extern "C" void func_00575DA0(s32 arg0);
extern "C" void (*D_0064B71C)(s32);

extern "C" s32 func_00538C68(s32 *arg0) {
    s32 temp_a0 = *arg0;
    if (temp_a0 != 0) {
        void (*fp)(s32) = D_0064B71C;
        if (fp == 0) {
            func_00575DA0(temp_a0);
        } else {
            fp(temp_a0);
        }
        *arg0 = 0;
    }
    return 0;
}
