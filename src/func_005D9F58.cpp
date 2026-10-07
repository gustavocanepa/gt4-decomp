typedef unsigned int u32;

extern "C" void func_005CB130();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00697C58[];
extern int D_006D5E60;

static int D_0088D9A0;

extern "C" void *func_005D9F58(void) {
    if (D_0088D9A0 == 0) {
        func_005CB130();
        func_005BFB68(&D_0088D9A0, D_00697C58, &D_006D5E60);
    }
    return &D_0088D9A0;
}
