typedef unsigned int u32;

extern "C" void func_005FA678();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A1B68[];
extern int D_006D5FC8;

extern int D_0088F580;

extern "C" void *func_005F98C0(void) {
    if (D_0088F580 == 0) {
        func_005FA678();
        func_005BFB68(&D_0088F580, D_006A1B68, &D_006D5FC8);
    }
    return &D_0088F580;
}
