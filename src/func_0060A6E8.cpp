typedef unsigned int u32;

extern "C" void func_0060B780();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006B00D8[];
extern int D_008A0020;

static int D_0088D9A0;

extern "C" void *func_0060A6E8(void) {
    if (D_0088D9A0 == 0) {
        func_0060B780();
        func_005BFB68(&D_0088D9A0, D_006B00D8, &D_008A0020);
    }
    return &D_0088D9A0;
}
