typedef unsigned int u32;

extern "C" void func_00615B98();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006CF878[];
extern int D_006D62E8;

static int D_0088D9A0;

extern "C" void *func_00615148(void) {
    if (D_0088D9A0 == 0) {
        func_00615B98();
        func_005BFB68(&D_0088D9A0, D_006CF878, &D_006D62E8);
    }
    return &D_0088D9A0;
}
