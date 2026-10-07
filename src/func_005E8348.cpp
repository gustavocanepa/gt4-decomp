typedef unsigned int u32;

extern "C" void func_005EA250();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069C040[];
extern int D_0088E910;

static int D_0088D9A0;

extern "C" void *func_005E8348(void) {
    if (D_0088D9A0 == 0) {
        func_005EA250();
        func_005BFB68(&D_0088D9A0, D_0069C040, &D_0088E910);
    }
    return &D_0088D9A0;
}
