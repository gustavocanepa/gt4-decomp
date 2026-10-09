typedef unsigned int u32;

extern "C" void func_005C28F8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088DA50;

extern int D_0088D9B0;

extern "C" void *func_005C20F0(void) {
    if (D_0088D9B0 == 0) {
        func_005C28F8();
        func_005BFB68(&D_0088D9B0, ((char *)"Q212GranTurismo410LoadingPS2"), &D_0088DA50);
    }
    return &D_0088D9B0;
}
