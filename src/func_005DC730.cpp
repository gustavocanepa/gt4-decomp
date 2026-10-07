typedef unsigned int u32;

extern "C" void func_005DC658();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00699040[];
extern int D_0088E2A0;

static int D_0088D9A0;

extern "C" void *func_005DC730(void) {
    if (D_0088D9A0 == 0) {
        func_005DC658();
        func_005BFB68(&D_0088D9A0, D_00699040, &D_0088E2A0);
    }
    return &D_0088D9A0;
}
