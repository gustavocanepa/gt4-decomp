typedef unsigned int u32;

extern "C" void hObject__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00691538[];
extern int D_0088EB70;

extern int D_0088DC60;

extern "C" void *mMemoryCardPlayList__tf(void) {
    if (D_0088DC60 == 0) {
        hObject__tf();
        func_005BFB68(&D_0088DC60, D_00691538, &D_0088EB70);
    }
    return &D_0088DC60;
}
