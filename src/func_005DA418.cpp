extern "C" void func_005E5760();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00697E08[];
extern int D_0088E5D0;

static int D_0088E150;

extern "C" void *func_005DA418(void) {
    if (D_0088E150 == 0) {
        func_005E5760();
        func_005BFB68(&D_0088E150, D_00697E08, &D_0088E5D0);
    }
    return &D_0088E150;
}
