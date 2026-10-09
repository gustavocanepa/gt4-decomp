typedef unsigned int u32;

extern "C" void MReaderBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069B838[];
extern int D_006D5EA8;

extern int D_0088E700;

extern "C" void *func_005E64B8(void) {
    if (D_0088E700 == 0) {
        MReaderBase__tf();
        func_005BFB68(&D_0088E700, D_0069B838, &D_006D5EA8);
    }
    return &D_0088E700;
}
