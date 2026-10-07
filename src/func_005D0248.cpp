typedef unsigned int u32;

extern "C" void func_005CF710();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00693A40[];
extern int D_0088DDB0;

extern int D_0088DDC0;

extern "C" void *func_005D0248(void) {
    if (D_0088DDC0 == 0) {
        func_005CF710();
        func_005BFB68(&D_0088DDC0, D_00693A40, &D_0088DDB0);
    }
    return &D_0088DDC0;
}
