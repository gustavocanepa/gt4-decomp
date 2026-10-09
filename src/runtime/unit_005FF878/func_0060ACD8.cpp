typedef unsigned int u32;

extern "C" void func_0060AD40();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D61A8;

extern int D_0088FF48;

extern "C" void *func_0060ACD8(void) {
    if (D_0088FF48 == 0) {
        func_0060AD40();
        func_005BFB68(&D_0088FF48, ((char *)"Q26PDISTD9FileGroup"), &D_006D61A8);
    }
    return &D_0088FF48;
}
