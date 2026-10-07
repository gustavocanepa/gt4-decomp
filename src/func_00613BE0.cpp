extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006CC890[];

static int D_006D5E18;

extern "C" void *func_00613BE0(void) {
    if (D_006D5E18 == 0) {
        func_005BFB88(&D_006D5E18, D_006CC890);
    }
    return &D_006D5E18;
}
