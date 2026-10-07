typedef unsigned int u32;

extern "C" void func_005EFF90();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00692A68[];
extern int D_0088EB70;

extern int D_0088DCE0;

extern "C" void *func_005CDFF8(void) {
    if (D_0088DCE0 == 0) {
        func_005EFF90();
        func_005BFB68(&D_0088DCE0, D_00692A68, &D_0088EB70);
    }
    return &D_0088DCE0;
}
