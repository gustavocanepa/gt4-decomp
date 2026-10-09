typedef unsigned int u32;

extern "C" void mWidget__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0068EE48[];
extern int D_0088E3B0;

extern int D_0088DAF0;

extern "C" void *mCarFace__tf(void) {
    if (D_0088DAF0 == 0) {
        mWidget__tf();
        func_005BFB68(&D_0088DAF0, D_0068EE48, &D_0088E3B0);
    }
    return &D_0088DAF0;
}
