typedef unsigned int u32;

extern "C" void func_006124D8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D6278;

extern int D_0088FB20;

extern "C" void *PhotoModeInput__tf(void) {
    if (D_0088FB20 == 0) {
        func_006124D8();
        func_005BFB68(&D_0088FB20, ((char *)"14PhotoModeInput"), &D_006D6278);
    }
    return &D_0088FB20;
}
