typedef unsigned int u32;

extern "C" void hArrayCompare__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069D600[];
extern int D_006D5E30;

extern int D_0088EA10;

extern "C" void *FunctionCompare__tf(void) {
    if (D_0088EA10 == 0) {
        hArrayCompare__tf();
        func_005BFB68(&D_0088EA10, D_0069D600, &D_006D5E30);
    }
    return &D_0088EA10;
}
