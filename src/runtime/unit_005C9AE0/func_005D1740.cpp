typedef unsigned int u32;

extern "C" void func_005D1680();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088DF00;

extern int D_0088DEC0;

extern "C" void *func_005D1740(void) {
    if (D_0088DEC0 == 0) {
        func_005D1680();
        func_005BFB68(&D_0088DEC0, ((char *)"Q25GT4MC16FileGT4PatchData"), &D_0088DF00);
    }
    return &D_0088DEC0;
}
