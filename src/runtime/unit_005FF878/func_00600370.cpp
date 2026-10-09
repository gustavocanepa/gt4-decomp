typedef unsigned int u32;

extern "C" void func_006006B0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088FBB0;

extern int D_0088FB40;

extern "C" void *func_00600370(void) {
    if (D_0088FB40 == 0) {
        func_006006B0();
        func_005BFB68(&D_0088FB40, ((char *)"Q210GT4_Motion18RenderCallBackBase"), &D_0088FBB0);
    }
    return &D_0088FB40;
}
