typedef unsigned int u32;

extern "C" void func_00612CD0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006B0270[];
extern int D_006D62A0;

extern int D_0089FFC0;

extern "C" void *func_0060B2C0(void) {
    if (D_0089FFC0 == 0) {
        func_00612CD0();
        func_005BFB68(&D_0089FFC0, D_006B0270, &D_006D62A0);
    }
    return &D_0089FFC0;
}
