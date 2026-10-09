typedef unsigned int u32;

extern "C" void hObject__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069E1B8[];
extern int D_0088EB70;

extern int D_0088EBB0;

extern "C" void *hString__tf(void) {
    if (D_0088EBB0 == 0) {
        hObject__tf();
        func_005BFB68(&D_0088EBB0, D_0069E1B8, &D_0088EB70);
    }
    return &D_0088EBB0;
}
