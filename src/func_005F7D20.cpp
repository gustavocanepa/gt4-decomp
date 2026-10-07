typedef unsigned int u32;

extern "C" void func_005F7BB0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A1378[];
extern int D_0088F390;

static int D_0088D9A0;

extern "C" void *func_005F7D20(void) {
    if (D_0088D9A0 == 0) {
        func_005F7BB0();
        func_005BFB68(&D_0088D9A0, D_006A1378, &D_0088F390);
    }
    return &D_0088D9A0;
}
