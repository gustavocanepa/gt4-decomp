typedef unsigned int u32;

extern "C" void func_0060B6D8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006B0368[];
extern int D_008A0010;

extern int D_008A0020;

extern "C" void *func_0060B780(void) {
    if (D_008A0020 == 0) {
        func_0060B6D8();
        func_005BFB68(&D_008A0020, D_006B0368, &D_008A0010);
    }
    return &D_008A0020;
}
