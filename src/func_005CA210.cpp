typedef unsigned int u32;

extern "C" void func_005EFF90();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0068FD08[];
extern int D_0088EB70;

extern int D_0088DB40;

extern "C" void *func_005CA210(void) {
    if (D_0088DB40 == 0) {
        func_005EFF90();
        func_005BFB68(&D_0088DB40, D_0068FD08, &D_0088EB70);
    }
    return &D_0088DB40;
}
