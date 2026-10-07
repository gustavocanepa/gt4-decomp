typedef unsigned int u32;

extern "C" void func_005FB5D8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A4340[];
extern int D_0088F750;

static int D_0088D9A0;

extern "C" void *func_005FF2A8(void) {
    if (D_0088D9A0 == 0) {
        func_005FB5D8();
        func_005BFB68(&D_0088D9A0, D_006A4340, &D_0088F750);
    }
    return &D_0088D9A0;
}
