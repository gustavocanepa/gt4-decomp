typedef int s32;

extern "C" void func_004B96F0(void *, const char *, s32);
extern "C" void func_00146C20(s32, void *);

extern "C" void func_00146CE8(s32 arg0, const char *arg1) {
    short buf[0x80];
    if (*arg1 != 0) {
        func_004B96F0(buf, arg1, 0x80);
        func_00146C20(arg0, buf);
    }
}
