typedef unsigned int u32;

extern "C" void func_0060F650();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006C0F40[];
extern int D_006D6220;

static int D_0088D9A0;

extern "C" void *func_0060F690(void) {
    if (D_0088D9A0 == 0) {
        func_0060F650();
        func_005BFB68(&D_0088D9A0, D_006C0F40, &D_006D6220);
    }
    return &D_0088D9A0;
}
