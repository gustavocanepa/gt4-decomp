typedef unsigned int u32;

extern "C" void func_00612828();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D6280;

extern int D_008A1B30;

extern "C" void *func_00612970(void) {
    if (D_008A1B30 == 0) {
        func_00612828();
        func_005BFB68(&D_008A1B30, ((char *)"Q26PDIUSB7userial"), &D_006D6280);
    }
    return &D_008A1B30;
}
