typedef unsigned int u32;

extern "C" void func_00603D80();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069FA88[];
extern int D_006D6100;

static int D_0088D9A0;

extern "C" void *func_005F5550(void) {
    if (D_0088D9A0 == 0) {
        func_00603D80();
        func_005BFB68(&D_0088D9A0, D_0069FA88, &D_006D6100);
    }
    return &D_0088D9A0;
}
