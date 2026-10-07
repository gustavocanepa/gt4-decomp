typedef unsigned int u32;

extern "C" void func_005E5988();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00698C78[];
extern int D_0088E600;

static int D_0088D9A0;

extern "C" void *func_005DBEA0(void) {
    if (D_0088D9A0 == 0) {
        func_005E5988();
        func_005BFB68(&D_0088D9A0, D_00698C78, &D_0088E600);
    }
    return &D_0088D9A0;
}
