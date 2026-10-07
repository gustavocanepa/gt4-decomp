extern "C" void func_005BFB88(void *a0, void *a1);

extern char D_006A0118[];

extern int D_006D5FA0;

extern "C" void *func_005F6C50(void) {
    if (D_006D5FA0 == 0) {
        func_005BFB88(&D_006D5FA0, D_006A0118);
    }
    return &D_006D5FA0;
}
