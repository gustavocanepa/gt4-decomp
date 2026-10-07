extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006A2640[];

extern int D_006D5FF8;

extern "C" void *func_005FB040(void) {
    if (D_006D5FF8 == 0) {
        func_005BFB88(&D_006D5FF8, D_006A2640);
    }
    return &D_006D5FF8;
}
