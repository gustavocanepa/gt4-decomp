typedef unsigned int u32;

extern "C" void func_00616E00();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006D31F0[];
extern int D_006D6308;

extern int D_008A2150;

extern "C" void *func_00616E88(void) {
    if (D_008A2150 == 0) {
        func_00616E00();
        func_005BFB68(&D_008A2150, D_006D31F0, &D_006D6308);
    }
    return &D_008A2150;
}
