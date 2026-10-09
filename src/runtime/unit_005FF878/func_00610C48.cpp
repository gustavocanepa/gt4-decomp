typedef unsigned int u32;

extern "C" void func_00612828();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D6280;

extern int D_008A1A20;

extern "C" void *func_00610C48(void) {
    if (D_008A1A20 == 0) {
        func_00612828();
        func_005BFB68(&D_008A1A20, ((char *)"Q26PDIUSB3ums"), &D_006D6280);
    }
    return &D_008A1A20;
}
