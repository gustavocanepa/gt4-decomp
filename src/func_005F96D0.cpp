typedef unsigned int u32;

extern "C" void func_005F8188();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A1B20[];
extern int D_0088F4A0;

extern int D_0088F520;

extern "C" void *func_005F96D0(void) {
    if (D_0088F520 == 0) {
        func_005F8188();
        func_005BFB68(&D_0088F520, D_006A1B20, &D_0088F4A0);
    }
    return &D_0088F520;
}
