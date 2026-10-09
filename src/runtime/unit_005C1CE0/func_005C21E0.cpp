typedef unsigned int u32;

extern "C" void func_005C2188();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088D9D0;

extern int D_0088D9E0;

extern "C" void *func_005C21E0(void) {
    if (D_0088D9E0 == 0) {
        func_005C2188();
        func_005BFB68(&D_0088D9E0, ((char *)"Q212GranTurismo424LoadingConfigPS2FadeBase"), &D_0088D9D0);
    }
    return &D_0088D9E0;
}
