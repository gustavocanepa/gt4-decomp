typedef unsigned int u32;

extern "C" void func_00602300();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A6650[];
extern int D_006D60A8;

static int D_0088D9A0;

extern "C" void *func_00602FE0(void) {
    if (D_0088D9A0 == 0) {
        func_00602300();
        func_005BFB68(&D_0088D9A0, D_006A6650, &D_006D60A8);
    }
    return &D_0088D9A0;
}
