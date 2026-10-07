typedef unsigned int u32;

extern "C" void func_005DEA30();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0068EE48[];
extern int D_0088E3B0;

static int D_0088D9A0;

extern "C" void *func_005C4EB0(void) {
    if (D_0088D9A0 == 0) {
        func_005DEA30();
        func_005BFB68(&D_0088D9A0, D_0068EE48, &D_0088E3B0);
    }
    return &D_0088D9A0;
}
