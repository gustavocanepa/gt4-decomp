extern "C" void *D_00623998;
extern "C" void *D_0062399C;
extern "C" int D_006239A0;
extern "C" void func_00575DA0(void *p);

extern "C" void func_0045FF00(void) {
    if (D_00623998) {
        void *p = D_00623998;
        D_00623998 = 0;
        func_00575DA0(p);
        p = D_0062399C;
        D_0062399C = 0;
        func_00575DA0(p);
        D_006239A0 = 0;
    }
}
