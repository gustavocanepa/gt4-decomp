typedef unsigned int u32;

extern "C" void func_006124D8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069A3B8[];
extern int D_006D6278;

static int D_0088D9A0;

extern "C" void *func_005DF900(void) {
    if (D_0088D9A0 == 0) {
        func_006124D8();
        func_005BFB68(&D_0088D9A0, D_0069A3B8, &D_006D6278);
    }
    return &D_0088D9A0;
}
