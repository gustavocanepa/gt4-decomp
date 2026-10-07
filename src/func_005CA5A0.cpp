typedef unsigned int u32;

extern "C" void func_005CA878();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0068FE40[];
extern int D_006D5E58;

static int D_0088D9A0;

extern "C" void *func_005CA5A0(void) {
    if (D_0088D9A0 == 0) {
        func_005CA878();
        func_005BFB68(&D_0088D9A0, D_0068FE40, &D_006D5E58);
    }
    return &D_0088D9A0;
}
