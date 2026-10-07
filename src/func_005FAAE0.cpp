typedef unsigned int u32;

extern "C" void func_00604AB0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A2400[];
extern int D_006D6110;

extern int D_0088F6A0;

extern "C" void *func_005FAAE0(void) {
    if (D_0088F6A0 == 0) {
        func_00604AB0();
        func_005BFB68(&D_0088F6A0, D_006A2400, &D_006D6110);
    }
    return &D_0088F6A0;
}
