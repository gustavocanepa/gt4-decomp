typedef unsigned int u32;

extern "C" void func_005F7AB0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A1398[];
extern int D_006D5FC0;

static int D_0088D9A0;

extern "C" void *func_005F7DA0(void) {
    if (D_0088D9A0 == 0) {
        func_005F7AB0();
        func_005BFB68(&D_0088D9A0, D_006A1398, &D_006D5FC0);
    }
    return &D_0088D9A0;
}
