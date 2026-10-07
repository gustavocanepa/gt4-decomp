typedef unsigned int u32;

extern "C" void func_005F8188();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A1AB0[];
extern int D_0088F4A0;

static int D_0088D9A0;

extern "C" void *func_005F9390(void) {
    if (D_0088D9A0 == 0) {
        func_005F8188();
        func_005BFB68(&D_0088D9A0, D_006A1AB0, &D_0088F4A0);
    }
    return &D_0088D9A0;
}
