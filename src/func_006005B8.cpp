typedef unsigned int u32;

extern "C" void func_006006B0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A4D08[];
extern int D_0088FBB0;

static int D_0088D9A0;

extern "C" void *func_006005B8(void) {
    if (D_0088D9A0 == 0) {
        func_006006B0();
        func_005BFB68(&D_0088D9A0, D_006A4D08, &D_0088FBB0);
    }
    return &D_0088D9A0;
}
