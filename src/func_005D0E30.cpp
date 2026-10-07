typedef unsigned int u32;

extern "C" void func_005D0F10();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00694C20[];
extern int D_006D5E90;

static int D_0088D9A0;

extern "C" void *func_005D0E30(void) {
    if (D_0088D9A0 == 0) {
        func_005D0F10();
        func_005BFB68(&D_0088D9A0, D_00694C20, &D_006D5E90);
    }
    return &D_0088D9A0;
}
