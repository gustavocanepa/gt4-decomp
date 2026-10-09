typedef int s32;

extern "C" void func_0027E6F0(void *buf);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);
extern "C" void func_0027E120(void *buf, s32 arg1);

extern "C" void MButtonActor__global_008331A0(s32 *arg0) {
    s32 buf[4];

    func_0027E6F0(buf);
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
    func_0027E120(buf, 2);
}
