typedef unsigned int u32;

extern "C" void func_005C1F98();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0068CF80[];
extern int D_0088D960;

static int D_0088D9A0;

extern "C" void *func_005C28F8(void) {
    if (D_0088D9A0 == 0) {
        func_005C1F98();
        func_005BFB68(&D_0088D9A0, D_0068CF80, &D_0088D960);
    }
    return &D_0088D9A0;
}
