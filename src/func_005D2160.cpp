typedef unsigned int u32;

extern "C" void func_005D0C00();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006952F0[];
extern int D_006D5E80;

static int D_0088D9A0;

extern "C" void *func_005D2160(void) {
    if (D_0088D9A0 == 0) {
        func_005D0C00();
        func_005BFB68(&D_0088D9A0, D_006952F0, &D_006D5E80);
    }
    return &D_0088D9A0;
}
