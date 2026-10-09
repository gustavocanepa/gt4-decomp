typedef unsigned int u32;

extern "C" void func_0060A750();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D61A0;

extern int D_0089FFE0;

extern "C" void *func_0060B3B8(void) {
    if (D_0089FFE0 == 0) {
        func_0060A750();
        func_005BFB68(&D_0089FFE0, ((char *)"Q212PlayStation214FileDevicePipe"), &D_006D61A0);
    }
    return &D_0089FFE0;
}
