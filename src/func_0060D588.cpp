typedef unsigned int u32;

extern "C" void func_0060D4E0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006BA300[];
extern int D_006D61C8;

static int D_0088D9A0;

extern "C" void *func_0060D588(void) {
    if (D_0088D9A0 == 0) {
        func_0060D4E0();
        func_005BFB68(&D_0088D9A0, D_006BA300, &D_006D61C8);
    }
    return &D_0088D9A0;
}
