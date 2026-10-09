typedef unsigned int u32;

extern "C" void func_00600260();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A4C98[];
extern int D_006D6090;

extern int D_0088FB80;

extern "C" void *func_006004E8(void) {
    if (D_0088FB80 == 0) {
        func_00600260();
        func_005BFB68(&D_0088FB80, D_006A4C98, &D_006D6090);
    }
    return &D_0088FB80;
}
