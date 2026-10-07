typedef unsigned int u32;

extern "C" void func_005D8A88();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00697268[];
extern int D_006D5EA8;

extern int D_0088E030;

extern "C" void *func_005D5180(void) {
    if (D_0088E030 == 0) {
        func_005D8A88();
        func_005BFB68(&D_0088E030, D_00697268, &D_006D5EA8);
    }
    return &D_0088E030;
}
