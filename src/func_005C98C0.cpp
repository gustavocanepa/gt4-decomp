typedef unsigned int u32;

extern "C" void func_005EFF90();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0068F550[];
extern int D_0088EB70;

extern int D_0088DB00;

extern "C" void *func_005C98C0(void) {
    if (D_0088DB00 == 0) {
        func_005EFF90();
        func_005BFB68(&D_0088DB00, D_0068F550, &D_0088EB70);
    }
    return &D_0088DB00;
}
