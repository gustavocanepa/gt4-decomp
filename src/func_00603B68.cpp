extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006A7C48[];

static int D_006D5E18;

extern "C" void *func_00603B68(void) {
    if (D_006D5E18 == 0) {
        func_005BFB88(&D_006D5E18, D_006A7C48);
    }
    return &D_006D5E18;
}
