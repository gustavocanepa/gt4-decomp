typedef unsigned int u32;

extern "C" void func_0060B870();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006B0340[];
extern int D_006D61C0;

extern int D_008A0030;

extern "C" void *func_0060B730(void) {
    if (D_008A0030 == 0) {
        func_0060B870();
        func_005BFB68(&D_008A0030, D_006B0340, &D_006D61C0);
    }
    return &D_008A0030;
}
