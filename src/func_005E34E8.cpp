typedef unsigned int u32;

extern "C" void func_005DA4B8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069A538[];
extern int D_0088E170;

extern int D_0088E470;

extern "C" void *func_005E34E8(void) {
    if (D_0088E470 == 0) {
        func_005DA4B8();
        func_005BFB68(&D_0088E470, D_0069A538, &D_0088E170);
    }
    return &D_0088E470;
}
