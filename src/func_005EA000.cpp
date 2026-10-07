typedef unsigned int u32;

extern "C" void func_005DD950();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069C9A8[];
extern int D_0088E370;

static int D_0088D9A0;

extern "C" void *func_005EA000(void) {
    if (D_0088D9A0 == 0) {
        func_005DD950();
        func_005BFB68(&D_0088D9A0, D_0069C9A8, &D_0088E370);
    }
    return &D_0088D9A0;
}
