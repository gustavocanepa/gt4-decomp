typedef unsigned int u32;

extern "C" void func_005F4E28();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069F528[];
extern int D_006D5F80;

static int D_0088D9A0;

extern "C" void *func_005F4C58(void) {
    if (D_0088D9A0 == 0) {
        func_005F4E28();
        func_005BFB68(&D_0088D9A0, D_0069F528, &D_006D5F80);
    }
    return &D_0088D9A0;
}
