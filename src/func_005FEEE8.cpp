typedef unsigned int u32;

extern "C" void func_005F4E28();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A40D8[];
extern int D_006D5F80;

extern int D_0088FA00;

extern "C" void *func_005FEEE8(void) {
    if (D_0088FA00 == 0) {
        func_005F4E28();
        func_005BFB68(&D_0088FA00, D_006A40D8, &D_006D5F80);
    }
    return &D_0088FA00;
}
