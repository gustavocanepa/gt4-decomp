typedef unsigned int u32;

extern "C" void func_0060B088();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006B0230[];
extern int D_006D61B0;

extern int D_0088FF78;

extern "C" void *func_0060B0C8(void) {
    if (D_0088FF78 == 0) {
        func_0060B088();
        func_005BFB68(&D_0088FF78, D_006B0230, &D_006D61B0);
    }
    return &D_0088FF78;
}
