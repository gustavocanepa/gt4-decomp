extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006A4BE0[];

extern int D_006D6090;

extern "C" void *func_00600260(void) {
    if (D_006D6090 == 0) {
        func_005BFB88(&D_006D6090, D_006A4BE0);
    }
    return &D_006D6090;
}
