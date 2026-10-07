typedef unsigned int u32;

extern "C" void func_005CB708();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00690F30[];
extern int D_006D5E68;

extern int D_0088DC40;

extern "C" void *func_005CB780(void) {
    if (D_0088DC40 == 0) {
        func_005CB708();
        func_005BFB68(&D_0088DC40, D_00690F30, &D_006D5E68);
    }
    return &D_0088DC40;
}
