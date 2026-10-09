typedef unsigned int u32;

extern "C" void func_005FFA90();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088FAF0;

extern int D_0088FB00;

extern "C" void *func_005FFB88(void) {
    if (D_0088FB00 == 0) {
        func_005FFA90();
        func_005BFB68(&D_0088FB00, ((char *)"Q211pdiRiderman9PlateBone"), &D_0088FAF0);
    }
    return &D_0088FB00;
}
