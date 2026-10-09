typedef unsigned int u32;

extern "C" void func_00600260();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D6090;

extern int D_0088FBE0;

extern "C" void *func_00600768(void) {
    if (D_0088FBE0 == 0) {
        func_00600260();
        func_005BFB68(&D_0088FBE0, ((char *)"Q210GT4_Motion21LightingCheckCallBack"), &D_006D6090);
    }
    return &D_0088FBE0;
}
