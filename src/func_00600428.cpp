typedef unsigned int u32;

extern "C" void func_00600370();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A4C48[];
extern int D_0088FB40;

static int D_0088D9A0;

extern "C" void *func_00600428(void) {
    if (D_0088D9A0 == 0) {
        func_00600370();
        func_005BFB68(&D_0088D9A0, D_006A4C48, &D_0088FB40);
    }
    return &D_0088D9A0;
}
