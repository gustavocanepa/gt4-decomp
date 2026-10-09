typedef unsigned int u32;

extern "C" void func_00600260();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A4BB8[];
extern int D_006D6090;

extern int D_0088FB30;

extern "C" void *func_006001F0(void) {
    if (D_0088FB30 == 0) {
        func_00600260();
        func_005BFB68(&D_0088FB30, D_006A4BB8, &D_006D6090);
    }
    return &D_0088FB30;
}
