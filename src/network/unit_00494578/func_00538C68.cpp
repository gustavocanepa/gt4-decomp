typedef int s32;

extern "C" void free(s32 arg0);
extern "C" void (*D_0064B71C)(s32);

extern "C" s32 func_00538C68(s32 *arg0) {
    s32 temp_a0 = *arg0;
    if (temp_a0 != 0) {
        void (*fp)(s32) = D_0064B71C;
        if (fp == 0) {
            free(temp_a0);
        } else {
            fp(temp_a0);
        }
        *arg0 = 0;
    }
    return 0;
}
