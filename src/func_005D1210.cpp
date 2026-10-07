typedef unsigned int u32;

extern "C" void func_005CB708();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00694F70[];
extern int D_006D5E68;

static int D_0088D9A0;

extern "C" void *func_005D1210(void) {
    if (D_0088D9A0 == 0) {
        func_005CB708();
        func_005BFB68(&D_0088D9A0, D_00694F70, &D_006D5E68);
    }
    return &D_0088D9A0;
}
