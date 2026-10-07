typedef unsigned int u32;

extern "C" void func_005F8188();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A1B08[];
extern int D_0088F4A0;

extern int D_0088F460;

extern "C" void *func_005F95F8(void) {
    if (D_0088F460 == 0) {
        func_005F8188();
        func_005BFB68(&D_0088F460, D_006A1B08, &D_0088F4A0);
    }
    return &D_0088F460;
}
