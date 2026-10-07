typedef unsigned int u32;

extern "C" void func_005CA3B8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0068FD18[];
extern int D_0088DB50;

extern int D_0088DB30;

extern "C" void *func_005CA328(void) {
    if (D_0088DB30 == 0) {
        func_005CA3B8();
        func_005BFB68(&D_0088DB30, D_0068FD18, &D_0088DB50);
    }
    return &D_0088DB30;
}
