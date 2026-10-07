typedef unsigned int u32;

extern "C" void func_005CA498();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006AB1F8[];
extern int D_006D5E50;

static int D_0088D9A0;

extern "C" void *func_00604BF0(void) {
    if (D_0088D9A0 == 0) {
        func_005CA498();
        func_005BFB68(&D_0088D9A0, D_006AB1F8, &D_006D5E50);
    }
    return &D_0088D9A0;
}
