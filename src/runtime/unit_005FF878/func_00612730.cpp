typedef unsigned int u32;

extern "C" void func_00612498();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006C8D18[];
extern int D_006D6270;

extern int D_008A1AD0;

extern "C" void *func_00612730(void) {
    if (D_008A1AD0 == 0) {
        func_00612498();
        func_005BFB68(&D_008A1AD0, D_006C8D18, &D_006D6270);
    }
    return &D_008A1AD0;
}
