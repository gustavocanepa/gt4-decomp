typedef unsigned int u32;

extern "C" void func_005D1260();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D5E98;

extern int D_0088DE80;

extern "C" void *func_005D1470(void) {
    if (D_0088DE80 == 0) {
        func_005D1260();
        func_005BFB68(&D_0088DE80, ((char *)"Q25GT4MC10FileBroken"), &D_006D5E98);
    }
    return &D_0088DE80;
}
