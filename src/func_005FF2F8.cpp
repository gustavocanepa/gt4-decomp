typedef unsigned int u32;

extern "C" void func_005FDCF0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A4498[];
extern int D_006D6040;

extern int D_0088FA70;

extern "C" void *func_005FF2F8(void) {
    if (D_0088FA70 == 0) {
        func_005FDCF0();
        func_005BFB68(&D_0088FA70, D_006A4498, &D_006D6040);
    }
    return &D_0088FA70;
}
