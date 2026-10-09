typedef int s32;

extern "C" void func_00138140(void *buf);
extern "C" void func_003285A8(s32 arg0);
extern "C" void func_003285F8(s32 arg0);
extern "C" void func_00137D60(void *buf, s32 arg1);

extern "C" void MCarFace__getImagePath(s32 *arg0) {
    s32 buf[4];

    func_00138140(buf);
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
    func_00137D60(buf, 2);
}
