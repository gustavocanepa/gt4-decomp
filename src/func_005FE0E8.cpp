typedef unsigned int u32;

extern "C" void func_005FE188();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A3808[];
extern int D_006D6048;

static int D_0088D9A0;

extern "C" void *func_005FE0E8(void) {
    if (D_0088D9A0 == 0) {
        func_005FE188();
        func_005BFB68(&D_0088D9A0, D_006A3808, &D_006D6048);
    }
    return &D_0088D9A0;
}
