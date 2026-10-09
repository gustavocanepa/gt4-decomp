typedef unsigned int u32;

extern "C" void func_00602780();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A6248[];
extern int D_006D60B0;

extern int D_0088FD10;

extern "C" void *func_00602660(void) {
    if (D_0088FD10 == 0) {
        func_00602780();
        func_005BFB68(&D_0088FD10, D_006A6248, &D_006D60B0);
    }
    return &D_0088FD10;
}
