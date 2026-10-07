typedef unsigned int u32;

extern "C" void func_005DB9E0();
extern "C" void func_005C0E78(void *a0, void *a1, void *a2);

extern char D_00698830[];
extern int D_0088E240;

static int D_0088D9A0;

extern "C" void *func_005DB330(void) {
    if (D_0088D9A0 == 0) {
        func_005DB9E0();
        func_005C0E78(&D_0088D9A0, D_00698830, &D_0088E240);
    }
    return &D_0088D9A0;
}
