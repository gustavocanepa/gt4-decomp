typedef unsigned int u32;

extern "C" void func_005F75B0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A0400[];
extern int D_006D5FB8;

extern int D_0088F310;

extern "C" void *func_005F75F0(void) {
    if (D_0088F310 == 0) {
        func_005F75B0();
        func_005BFB68(&D_0088F310, D_006A0400, &D_006D5FB8);
    }
    return &D_0088F310;
}
