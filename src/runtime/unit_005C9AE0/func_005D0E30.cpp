typedef unsigned int u32;

extern "C" void func_005D0F10();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D5E90;

extern int D_0088DE70;

extern "C" void *func_005D0E30(void) {
    if (D_0088DE70 == 0) {
        func_005D0F10();
        func_005BFB68(&D_0088DE70, ((char *)"Q212PlayStation215UsbStorageDrive"), &D_006D5E90);
    }
    return &D_0088DE70;
}
