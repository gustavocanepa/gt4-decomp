typedef unsigned int u32;

extern "C" void hObject__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006931F0[];
extern int D_0088EB70;

extern int D_0088DD50;

extern "C" void *mUtility__tf(void) {
    if (D_0088DD50 == 0) {
        hObject__tf();
        func_005BFB68(&D_0088DD50, D_006931F0, &D_0088EB70);
    }
    return &D_0088DD50;
}
