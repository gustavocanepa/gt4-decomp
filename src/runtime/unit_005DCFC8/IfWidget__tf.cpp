typedef unsigned int u32;

extern "C" void MEventFilter__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069A0C8[];
extern int D_006D5EC8;

extern int D_0088E3A0;

extern "C" void *IfWidget__tf(void) {
    if (D_0088E3A0 == 0) {
        MEventFilter__tf();
        func_005BFB68(&D_0088E3A0, D_0069A0C8, &D_006D5EC8);
    }
    return &D_0088E3A0;
}
