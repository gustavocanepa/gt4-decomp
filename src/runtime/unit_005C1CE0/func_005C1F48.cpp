typedef unsigned int u32;

extern "C" void func_005C20A0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088D980;

extern int D_0088D990;

extern "C" void *func_005C1F48(void) {
    if (D_0088D990 == 0) {
        func_005C20A0();
        func_005BFB68(&D_0088D990, ((char *)"Q212GranTurismo413RenderManager"), &D_0088D980);
    }
    return &D_0088D990;
}
