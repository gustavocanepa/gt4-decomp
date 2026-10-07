typedef unsigned int u32;

extern "C" void func_005DF830();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069BBF8[];
extern int D_0088E400;

extern int D_0088E740;

extern "C" void *func_005E7958(void) {
    if (D_0088E740 == 0) {
        func_005DF830();
        func_005BFB68(&D_0088E740, D_0069BBF8, &D_0088E400);
    }
    return &D_0088E740;
}
