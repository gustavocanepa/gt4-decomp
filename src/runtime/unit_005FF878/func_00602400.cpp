typedef unsigned int u32;

extern "C" void func_00602780();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A6140[];
extern int D_006D60B0;

extern int D_0088FCE0;

extern "C" void *func_00602400(void) {
    if (D_0088FCE0 == 0) {
        func_00602780();
        func_005BFB68(&D_0088FCE0, D_006A6140, &D_006D60B0);
    }
    return &D_0088FCE0;
}
