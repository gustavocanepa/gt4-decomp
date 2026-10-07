typedef unsigned int u32;

extern "C" void func_005EE958();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069D828[];
extern int D_0088EAE0;

extern int D_0088EA80;

extern "C" void *func_005EE660(void) {
    if (D_0088EA80 == 0) {
        func_005EE958();
        func_005BFB68(&D_0088EA80, D_0069D828, &D_0088EAE0);
    }
    return &D_0088EA80;
}
