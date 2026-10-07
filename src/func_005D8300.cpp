typedef unsigned int u32;

extern "C" void func_005CA408();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00697678[];
extern int D_006D5E20;

static int D_0088D9A0;

extern "C" void *func_005D8300(void) {
    if (D_0088D9A0 == 0) {
        func_005CA408();
        func_005BFB68(&D_0088D9A0, D_00697678, &D_006D5E20);
    }
    return &D_0088D9A0;
}
