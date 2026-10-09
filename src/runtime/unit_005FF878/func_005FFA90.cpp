typedef unsigned int u32;

extern "C" void func_005FF9A8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088FAE0;

extern int D_0088FAF0;

extern "C" void *func_005FFA90(void) {
    if (D_0088FAF0 == 0) {
        func_005FF9A8();
        func_005BFB68(&D_0088FAF0, ((char *)"Q211pdiRiderman9StickBone"), &D_0088FAE0);
    }
    return &D_0088FAF0;
}
