typedef unsigned int u32;

extern "C" void func_0060B870();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006B0408[];
extern int D_006D61C0;

extern int D_008A0050;

extern "C" void *func_0060BB48(void) {
    if (D_008A0050 == 0) {
        func_0060B870();
        func_005BFB68(&D_008A0050, D_006B0408, &D_006D61C0);
    }
    return &D_008A0050;
}
