typedef unsigned int u32;

extern "C" void func_00604E00();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006AB4E8[];
extern int D_006D6118;

static int D_0088D9A0;

extern "C" void *func_00604DB0(void) {
    if (D_0088D9A0 == 0) {
        func_00604E00();
        func_005BFB68(&D_0088D9A0, D_006AB4E8, &D_006D6118);
    }
    return &D_0088D9A0;
}
