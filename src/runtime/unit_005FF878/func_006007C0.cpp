typedef unsigned int u32;

extern "C" void func_006006B0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A4E78[];
extern int D_0088FBB0;

extern int D_0088FBF0;

extern "C" void *func_006007C0(void) {
    if (D_0088FBF0 == 0) {
        func_006006B0();
        func_005BFB68(&D_0088FBF0, D_006A4E78, &D_0088FBB0);
    }
    return &D_0088FBF0;
}
