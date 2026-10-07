typedef unsigned int u32;

extern "C" void func_005E5988();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069AB50[];
extern int D_0088E600;

extern int D_0088E550;

extern "C" void *func_005E47B8(void) {
    if (D_0088E550 == 0) {
        func_005E5988();
        func_005BFB68(&D_0088E550, D_0069AB50, &D_0088E600);
    }
    return &D_0088E550;
}
