typedef unsigned int u32;

extern "C" void func_0060D4E0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006BA320[];
extern int D_006D61C8;

extern int D_008A0070;

extern "C" void *func_0060D768(void) {
    if (D_008A0070 == 0) {
        func_0060D4E0();
        func_005BFB68(&D_008A0070, D_006BA320, &D_006D61C8);
    }
    return &D_008A0070;
}
