typedef unsigned int u32;

extern "C" void func_005DCDB8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069AD40[];
extern int D_0088E2F0;

static int D_0088D9A0;

extern "C" void *func_005E5440(void) {
    if (D_0088D9A0 == 0) {
        func_005DCDB8();
        func_005BFB68(&D_0088D9A0, D_0069AD40, &D_0088E2F0);
    }
    return &D_0088D9A0;
}
