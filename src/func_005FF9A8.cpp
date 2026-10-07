typedef unsigned int u32;

extern "C" void func_005FFDD8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A4AC0[];
extern int D_006D6088;

static int D_0088D9A0;

extern "C" void *func_005FF9A8(void) {
    if (D_0088D9A0 == 0) {
        func_005FFDD8();
        func_005BFB68(&D_0088D9A0, D_006A4AC0, &D_006D6088);
    }
    return &D_0088D9A0;
}
