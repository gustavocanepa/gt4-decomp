typedef unsigned int u32;

extern "C" void func_005D0248();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00693CD0[];
extern int D_0088DDC0;

extern int D_0088DE20;

extern "C" void *func_005D09A0(void) {
    if (D_0088DE20 == 0) {
        func_005D0248();
        func_005BFB68(&D_0088DE20, D_00693CD0, &D_0088DDC0);
    }
    return &D_0088DE20;
}
