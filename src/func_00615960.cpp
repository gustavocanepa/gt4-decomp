typedef unsigned int u32;

extern "C" void func_00615388();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006CF890[];
extern int D_008A1C30;

static int D_0088D9A0;

extern "C" void *func_00615960(void) {
    if (D_0088D9A0 == 0) {
        func_00615388();
        func_005BFB68(&D_0088D9A0, D_006CF890, &D_008A1C30);
    }
    return &D_0088D9A0;
}
