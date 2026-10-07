typedef unsigned int u32;

extern "C" void func_005F1C50();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069DD50[];
extern int D_0088EEA0;

static int D_0088D9A0;

extern "C" void *func_005EFEF0(void) {
    if (D_0088D9A0 == 0) {
        func_005F1C50();
        func_005BFB68(&D_0088D9A0, D_0069DD50, &D_0088EEA0);
    }
    return &D_0088D9A0;
}
