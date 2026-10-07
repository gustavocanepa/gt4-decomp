typedef unsigned int u32;

extern "C" void func_005D50C8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069C180[];
extern int D_0088E020;

static int D_0088D9A0;

extern "C" void *func_005E86A0(void) {
    if (D_0088D9A0 == 0) {
        func_005D50C8();
        func_005BFB68(&D_0088D9A0, D_0069C180, &D_0088E020);
    }
    return &D_0088D9A0;
}
