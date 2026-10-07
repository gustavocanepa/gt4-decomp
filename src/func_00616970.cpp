typedef unsigned int u32;

extern "C" void func_00616370();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006D3128[];
extern int D_006D6300;

static int D_0088D9A0;

extern "C" void *func_00616970(void) {
    if (D_0088D9A0 == 0) {
        func_00616370();
        func_005BFB68(&D_0088D9A0, D_006D3128, &D_006D6300);
    }
    return &D_0088D9A0;
}
