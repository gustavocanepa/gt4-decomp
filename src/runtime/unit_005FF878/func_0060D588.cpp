typedef unsigned int u32;

extern "C" void func_0060D4E0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006BA300[];
extern int D_006D61C8;

extern int D_008A0080;

extern "C" void *func_0060D588(void) {
    if (D_008A0080 == 0) {
        func_0060D4E0();
        func_005BFB68(&D_008A0080, D_006BA300, &D_006D61C8);
    }
    return &D_008A0080;
}
