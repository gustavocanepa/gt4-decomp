typedef unsigned int u32;

extern "C" void func_005F6E50();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A0138[];
extern int D_006D5FA8;

static int D_0088D9A0;

extern "C" void *func_005F6D18(void) {
    if (D_0088D9A0 == 0) {
        func_005F6E50();
        func_005BFB68(&D_0088D9A0, D_006A0138, &D_006D5FA8);
    }
    return &D_0088D9A0;
}
