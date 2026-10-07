typedef int s32;

extern "C" void func_001BE060(void *buf);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);
extern "C" void func_001B9088(void *buf, s32 arg1);

extern "C" void func_005CF298(s32 *arg0) {
    s32 buf[4];

    func_001BE060(buf);
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
    func_001B9088(buf, 2);
}
