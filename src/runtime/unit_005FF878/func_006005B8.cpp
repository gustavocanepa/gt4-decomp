typedef unsigned int u32;

extern "C" void func_006006B0();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088FBB0;

extern int D_0088FB90;

extern "C" void *func_006005B8(void) {
    if (D_0088FB90 == 0) {
        func_006006B0();
        func_005BFB68(&D_0088FB90, ((char *)"Q210GT4_Motion14CameraCallBack"), &D_0088FBB0);
    }
    return &D_0088FB90;
}
