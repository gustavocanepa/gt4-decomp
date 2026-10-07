typedef unsigned int u32;

extern "C" void func_005FE4F0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A2708[];
extern int D_0088F8F0;

static int D_0088D9A0;

extern "C" void *func_005FB1B0(void) {
    if (D_0088D9A0 == 0) {
        func_005FE4F0();
        func_005BFB68(&D_0088D9A0, D_006A2708, &D_0088F8F0);
    }
    return &D_0088D9A0;
}
