typedef unsigned int u32;

extern "C" void HFrame__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D5F40;

extern int D_0088EC80;

extern "C" void *HTryCatchFrame__tf(void) {
    if (D_0088EC80 == 0) {
        HFrame__tf();
        func_005BFB68(&D_0088EC80, ((char *)"14HTryCatchFrame"), &D_006D5F40);
    }
    return &D_0088EC80;
}
