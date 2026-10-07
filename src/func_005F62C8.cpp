typedef unsigned int u32;

extern "C" void func_005F5550();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069FCF8[];
extern int D_0088F0B0;

static int D_0088D9A0;

extern "C" void *func_005F62C8(void) {
    if (D_0088D9A0 == 0) {
        func_005F5550();
        func_005BFB68(&D_0088D9A0, D_0069FCF8, &D_0088F0B0);
    }
    return &D_0088D9A0;
}
