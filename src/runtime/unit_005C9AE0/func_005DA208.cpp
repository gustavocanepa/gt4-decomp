typedef unsigned int u32;

extern "C" void func_005DA190();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D5EB0;

extern int D_0088E100;

extern "C" void *func_005DA208(void) {
    if (D_0088E100 == 0) {
        func_005DA190();
        func_005BFB68(&D_0088E100, ((char *)"Q25ADHOCt14PoolAllocatorN1i_20_"), &D_006D5EB0);
    }
    return &D_0088E100;
}
