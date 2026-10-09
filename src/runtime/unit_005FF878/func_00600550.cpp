typedef unsigned int u32;

extern "C" void func_00600260();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D6090;

extern int D_0088FBA0;

extern "C" void *func_00600550(void) {
    if (D_0088FBA0 == 0) {
        func_00600260();
        func_005BFB68(&D_0088FBA0, ((char *)"Q210GT4_Motion19CameraCheckCallBack"), &D_006D6090);
    }
    return &D_0088FBA0;
}
