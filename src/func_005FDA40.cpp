typedef unsigned int u32;

extern "C" void func_005FDDA8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A2D90[];
extern int D_0088F840;

static int D_0088D9A0;

extern "C" void *func_005FDA40(void) {
    if (D_0088D9A0 == 0) {
        func_005FDDA8();
        func_005BFB68(&D_0088D9A0, D_006A2D90, &D_0088F840);
    }
    return &D_0088D9A0;
}
