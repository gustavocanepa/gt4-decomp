typedef unsigned int u32;

extern "C" void func_0060B7D0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D61B8;

extern int D_008A0060;

extern "C" void *func_0060B8C0(void) {
    if (D_008A0060 == 0) {
        func_0060B7D0();
        func_005BFB68(&D_008A0060, ((char *)"Q35RoFS28Deflated11PageManager"), &D_006D61B8);
    }
    return &D_008A0060;
}
