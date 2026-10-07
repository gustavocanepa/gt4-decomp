typedef unsigned int u32;

extern "C" void func_00615960();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006CFFE8[];
extern int D_008A1C20;

static int D_0088D9A0;

extern "C" void *func_00615C18(void) {
    if (D_0088D9A0 == 0) {
        func_00615960();
        func_005BFB68(&D_0088D9A0, D_006CFFE8, &D_008A1C20);
    }
    return &D_0088D9A0;
}
