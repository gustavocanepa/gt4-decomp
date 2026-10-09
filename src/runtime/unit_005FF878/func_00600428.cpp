typedef unsigned int u32;

extern "C" void func_00600370();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088FB40;

extern int D_0088FB50;

extern "C" void *func_00600428(void) {
    if (D_0088FB50 == 0) {
        func_00600370();
        func_005BFB68(&D_0088FB50, ((char *)"Q210GT4_Motion19StoreMatrixCallBack"), &D_0088FB40);
    }
    return &D_0088FB50;
}
