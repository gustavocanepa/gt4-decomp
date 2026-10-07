typedef unsigned int u32;

extern "C" void func_005DD660();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00697CD8[];
extern int D_0088E340;

extern int D_0088E110;

extern "C" void *func_005DA0E0(void) {
    if (D_0088E110 == 0) {
        func_005DD660();
        func_005BFB68(&D_0088E110, D_00697CD8, &D_0088E340);
    }
    return &D_0088E110;
}
