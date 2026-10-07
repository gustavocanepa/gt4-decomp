typedef unsigned int u32;

extern "C" void func_00607408();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006AE338[];
extern int D_006D6170;

static int D_0088D9A0;

extern "C" void *func_00609F60(void) {
    if (D_0088D9A0 == 0) {
        func_00607408();
        func_005BFB68(&D_0088D9A0, D_006AE338, &D_006D6170);
    }
    return &D_0088D9A0;
}
