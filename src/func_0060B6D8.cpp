typedef unsigned int u32;

extern "C" void func_0060B3B8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006B0320[];
extern int D_0089FFE0;

static int D_0088D9A0;

extern "C" void *func_0060B6D8(void) {
    if (D_0088D9A0 == 0) {
        func_0060B3B8();
        func_005BFB68(&D_0088D9A0, D_006B0320, &D_0089FFE0);
    }
    return &D_0088D9A0;
}
