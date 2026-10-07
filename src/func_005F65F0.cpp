typedef unsigned int u32;

extern "C" void func_005C1F98();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069FE48[];
extern int D_0088D960;

extern int D_0088F210;

extern "C" void *func_005F65F0(void) {
    if (D_0088F210 == 0) {
        func_005C1F98();
        func_005BFB68(&D_0088F210, D_0069FE48, &D_0088D960);
    }
    return &D_0088F210;
}
