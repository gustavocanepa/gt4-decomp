typedef int s32;

extern "C" void func_004B96F0(void *, const char *, s32);
extern "C" void func_004B9A80(s32, s32, void *);

extern "C" void func_001D0438(s32 arg0, const char *arg1) {
    short buf[0x23];
    func_004B96F0(buf, arg1, 0x23);
    buf[0x22] = 0;
    func_004B9A80(arg0, 0x45, buf);
}
