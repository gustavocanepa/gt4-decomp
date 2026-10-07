typedef unsigned int u32;

extern "C" void func_00602780();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A6268[];
extern int D_006D60B0;

static int D_0088D9A0;

extern "C" void *func_00602730(void) {
    if (D_0088D9A0 == 0) {
        func_00602780();
        func_005BFB68(&D_0088D9A0, D_006A6268, &D_006D60B0);
    }
    return &D_0088D9A0;
}
