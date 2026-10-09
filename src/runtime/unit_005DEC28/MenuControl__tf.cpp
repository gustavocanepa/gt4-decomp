typedef unsigned int u32;

extern "C" void func_006124D8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069A3B8[];
extern int D_006D6278;

extern int D_0088E420;

extern "C" void *MenuControl__tf(void) {
    if (D_0088E420 == 0) {
        func_006124D8();
        func_005BFB68(&D_0088E420, D_0069A3B8, &D_006D6278);
    }
    return &D_0088E420;
}
