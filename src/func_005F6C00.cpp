typedef unsigned int u32;

extern "C" void func_005F6AB0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0068BC18[];
extern int D_008A1BA0;

static int D_0088D9A0;

extern "C" void *func_005F6C00(void) {
    if (D_0088D9A0 == 0) {
        func_005F6AB0();
        func_005BFB68(&D_0088D9A0, D_0068BC18, &D_008A1BA0);
    }
    return &D_0088D9A0;
}
