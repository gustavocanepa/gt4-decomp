typedef unsigned int u32;

extern "C" void func_005F39A8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A3BD8[];
extern int D_0088F040;

static int D_0088D9A0;

extern "C" void *func_005FE428(void) {
    if (D_0088D9A0 == 0) {
        func_005F39A8();
        func_005BFB68(&D_0088D9A0, D_006A3BD8, &D_0088F040);
    }
    return &D_0088D9A0;
}
