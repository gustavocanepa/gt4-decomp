typedef unsigned int u32;

extern "C" void func_0060B7D0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006B03A8[];
extern int D_006D61B8;

extern int D_008A0040;

extern "C" void *func_0060B820(void) {
    if (D_008A0040 == 0) {
        func_0060B7D0();
        func_005BFB68(&D_008A0040, D_006B03A8, &D_006D61B8);
    }
    return &D_008A0040;
}
