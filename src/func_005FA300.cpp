typedef unsigned int u32;

extern "C" void func_005F9D50();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A1C28[];
extern int D_0088F5F0;

extern int D_0088F680;

extern "C" void *func_005FA300(void) {
    if (D_0088F680 == 0) {
        func_005F9D50();
        func_005BFB68(&D_0088F680, D_006A1C28, &D_0088F5F0);
    }
    return &D_0088F680;
}
