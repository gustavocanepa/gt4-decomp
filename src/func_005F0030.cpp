typedef unsigned int u32;

extern "C" void func_005EEAA0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069E0D0[];
extern int D_0088EB20;

static int D_0088D9A0;

extern "C" void *func_005F0030(void) {
    if (D_0088D9A0 == 0) {
        func_005EEAA0();
        func_005BFB68(&D_0088D9A0, D_0069E0D0, &D_0088EB20);
    }
    return &D_0088D9A0;
}
