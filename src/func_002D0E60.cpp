typedef int s32;

extern "C" void func_002D0E08(void *buf);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);
extern "C" void func_002D0B78(void *buf, s32 arg1);

extern "C" void func_002D0E60(s32 *arg0) {
    s32 buf[4];

    func_002D0E08(buf);
    if (arg0 != buf) {
        s32 s0 = buf[0];
        if (s0 != 0) {
            func_003285A8(s0);
        }
        s32 temp_v0 = *arg0;
        if (temp_v0 != 0) {
            func_003285F8(temp_v0);
        }
        *arg0 = s0;
    }
    func_002D0B78(buf, 2);
}
