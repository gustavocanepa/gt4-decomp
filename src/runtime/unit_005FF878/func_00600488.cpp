typedef unsigned int u32;

extern "C" void func_00600718();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_0088FBD0;

extern int D_0088FB70;

extern "C" void *func_00600488(void) {
    if (D_0088FB70 == 0) {
        func_00600718();
        func_005BFB68(&D_0088FB70, ((char *)"Q210GT4_Motion19SimpleStoreCallBack"), &D_0088FBD0);
    }
    return &D_0088FB70;
}
