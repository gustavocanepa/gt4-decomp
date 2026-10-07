typedef unsigned int u32;

extern "C" void func_005C9848();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0068F598[];
extern int D_006D5E30;

static int D_0088D9A0;

extern "C" void *func_005C9AE0(void) {
    if (D_0088D9A0 == 0) {
        func_005C9848();
        func_005BFB68(&D_0088D9A0, D_0068F598, &D_006D5E30);
    }
    return &D_0088D9A0;
}
