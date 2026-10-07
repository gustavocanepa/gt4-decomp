typedef unsigned int u32;

extern "C" void func_005FE0E8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A4598[];
extern int D_0088F8B0;

static int D_0088D9A0;

extern "C" void *func_005FF560(void) {
    if (D_0088D9A0 == 0) {
        func_005FE0E8();
        func_005BFB68(&D_0088D9A0, D_006A4598, &D_0088F8B0);
    }
    return &D_0088D9A0;
}
