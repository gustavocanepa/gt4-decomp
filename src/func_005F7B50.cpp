typedef unsigned int u32;

extern "C" void func_005F7AF0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A1300[];
extern int D_0088F360;

static int D_0088D9A0;

extern "C" void *func_005F7B50(void) {
    if (D_0088D9A0 == 0) {
        func_005F7AF0();
        func_005BFB68(&D_0088D9A0, D_006A1300, &D_0088F360);
    }
    return &D_0088D9A0;
}
