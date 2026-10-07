typedef unsigned int u32;

extern "C" void func_005C2288();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0068BFD0[];
extern int D_0088D9F0;

static int D_0088D9A0;

extern "C" void *func_005C22D8(void) {
    if (D_0088D9A0 == 0) {
        func_005C2288();
        func_005BFB68(&D_0088D9A0, D_0068BFD0, &D_0088D9F0);
    }
    return &D_0088D9A0;
}
