typedef int s32;

extern "C" unsigned int func_0057F260(const char *);
extern "C" void func_004616A0();
extern "C" s32 func_00461448(const char *);

extern "C" s32 func_00461928(const char *s) {
    s32 r;
    if (!s || !func_0057F260(s)) {
        func_004616A0();
        r = -1;
    } else {
        r = func_00461448(s);
    }
    return r;
}
