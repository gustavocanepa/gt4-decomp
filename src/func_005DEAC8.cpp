typedef unsigned int u32;

extern "C" void func_005CB130();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069A030[];
extern int D_006D5E60;

extern int D_0088E390;

extern "C" void *func_005DEAC8(void) {
    if (D_0088E390 == 0) {
        func_005CB130();
        func_005BFB68(&D_0088E390, D_0069A030, &D_006D5E60);
    }
    return &D_0088E390;
}
