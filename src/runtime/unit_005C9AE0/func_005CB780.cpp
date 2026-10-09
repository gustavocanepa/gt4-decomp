typedef unsigned int u32;

extern "C" void func_005CB708();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D5E68;

extern int D_0088DC40;

extern "C" void *func_005CB780(void) {
    if (D_0088DC40 == 0) {
        func_005CB708();
        func_005BFB68(&D_0088DC40, ((char *)"Q35GT4MC4File8Progress"), &D_006D5E68);
    }
    return &D_0088DC40;
}
