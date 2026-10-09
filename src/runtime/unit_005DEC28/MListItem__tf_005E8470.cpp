typedef unsigned int u32;

extern "C" void RefPointer__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D5E20;

extern int D_0088E7A0;

extern "C" void *MListItem__tf(void) {
    if (D_0088E7A0 == 0) {
        RefPointer__tf();
        func_005BFB68(&D_0088E7A0, ((char *)"9MListItem"), &D_006D5E20);
    }
    return &D_0088E7A0;
}
