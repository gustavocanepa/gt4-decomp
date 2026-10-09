typedef unsigned int u32;

extern "C" void func_005C28B8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D5E18;

extern int D_0088D9D0;

extern "C" void *func_005C2188(void) {
    if (D_0088D9D0 == 0) {
        func_005C28B8();
        func_005BFB68(&D_0088D9D0, ((char *)"Q212GranTurismo416LoadingConfigPS2"), &D_006D5E18);
    }
    return &D_0088D9D0;
}
