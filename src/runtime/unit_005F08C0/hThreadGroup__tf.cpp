typedef unsigned int u32;

extern "C" void hObject__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069E830[];
extern int D_0088EB70;

extern int D_0088EE80;

extern "C" void *hThreadGroup__tf(void) {
    if (D_0088EE80 == 0) {
        hObject__tf();
        func_005BFB68(&D_0088EE80, D_0069E830, &D_0088EB70);
    }
    return &D_0088EE80;
}
