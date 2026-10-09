typedef int s32;

extern "C" void func_0027D1D8(void *buf);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);
extern "C" void func_0027CD98(void *buf, s32 arg1);

extern "C" void MButton__global_00832F60(s32 *arg0) {
    s32 buf[4];

    func_0027D1D8(buf);
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
    func_0027CD98(buf, 2);
}
