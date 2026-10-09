typedef unsigned int u32;

extern "C" void func_0060E910();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D61D0;

extern int D_008A00B0;

extern "C" void *func_0060E870(void) {
    if (D_008A00B0 == 0) {
        func_0060E910();
        func_005BFB68(&D_008A00B0, ((char *)"Q212PlayStation216NetworkInterface"), &D_006D61D0);
    }
    return &D_008A00B0;
}
