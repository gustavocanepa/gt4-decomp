typedef unsigned int u32;

extern "C" void func_00614028();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006CC560[];
extern int D_006D62E0;

extern int D_008A1B50;

extern "C" void *func_00612EC0(void) {
    if (D_008A1B50 == 0) {
        func_00614028();
        func_005BFB68(&D_008A1B50, D_006CC560, &D_006D62E0);
    }
    return &D_008A1B50;
}
