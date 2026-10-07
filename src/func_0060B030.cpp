typedef unsigned int u32;

extern "C" void func_0060AD40();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006B01F0[];
extern int D_006D61A8;

extern int D_0088FF58;

extern "C" void *func_0060B030(void) {
    if (D_0088FF58 == 0) {
        func_0060AD40();
        func_005BFB68(&D_0088FF58, D_006B01F0, &D_006D61A8);
    }
    return &D_0088FF58;
}
