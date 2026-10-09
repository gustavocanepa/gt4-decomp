typedef unsigned int u32;

extern "C" void func_005FFDD8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D6088;

extern int D_0088FAE0;

extern "C" void *func_005FF9A8(void) {
    if (D_0088FAE0 == 0) {
        func_005FFDD8();
        func_005BFB68(&D_0088FAE0, ((char *)"Q211pdiRiderman4Bone"), &D_006D6088);
    }
    return &D_0088FAE0;
}
