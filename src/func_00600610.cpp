typedef unsigned int u32;

extern "C" void func_00600260();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A4DB0[];
extern int D_006D6090;

static int D_0088D9A0;

extern "C" void *func_00600610(void) {
    if (D_0088D9A0 == 0) {
        func_00600260();
        func_005BFB68(&D_0088D9A0, D_006A4DB0, &D_006D6090);
    }
    return &D_0088D9A0;
}
