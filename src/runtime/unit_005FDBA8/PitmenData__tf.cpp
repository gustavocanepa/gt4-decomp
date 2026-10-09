typedef unsigned int u32;

extern "C" void ScenePack__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006A3228[];
extern int D_006D6040;

extern int D_0088F820;

extern "C" void *PitmenData__tf(void) {
    if (D_0088F820 == 0) {
        ScenePack__tf();
        func_005BFB68(&D_0088F820, D_006A3228, &D_006D6040);
    }
    return &D_0088F820;
}
