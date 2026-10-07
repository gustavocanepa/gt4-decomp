extern "C" void func_005FB200();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A3270[];
extern int D_006D6008;

static int D_0088F830;

extern "C" void *func_005FDD30(void) {
    if (D_0088F830 == 0) {
        func_005FB200();
        func_005BFB68(&D_0088F830, D_006A3270, &D_006D6008);
    }
    return &D_0088F830;
}
