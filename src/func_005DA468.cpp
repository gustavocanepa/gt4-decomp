typedef unsigned int u32;

extern "C" void func_005D4E00();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00697E98[];
extern int D_0088DFF0;

static int D_0088D9A0;

extern "C" void *func_005DA468(void) {
    if (D_0088D9A0 == 0) {
        func_005D4E00();
        func_005BFB68(&D_0088D9A0, D_00697E98, &D_0088DFF0);
    }
    return &D_0088D9A0;
}
