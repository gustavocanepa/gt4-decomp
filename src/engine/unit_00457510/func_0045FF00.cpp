extern "C" void *D_00623998;
extern "C" void *D_0062399C;
extern "C" int D_006239A0;
extern "C" void free(void *p);

extern "C" void func_0045FF00(void) {
    if (D_00623998) {
        void *p = D_00623998;
        D_00623998 = 0;
        free(p);
        p = D_0062399C;
        D_0062399C = 0;
        free(p);
        D_006239A0 = 0;
    }
}
