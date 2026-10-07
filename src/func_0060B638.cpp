typedef unsigned int u32;

extern "C" void func_00612E68();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006B02E0[];
extern int D_006D62A8;

static int D_0088D9A0;

extern "C" void *func_0060B638(void) {
    if (D_0088D9A0 == 0) {
        func_00612E68();
        func_005BFB68(&D_0088D9A0, D_006B02E0, &D_006D62A8);
    }
    return &D_0088D9A0;
}
