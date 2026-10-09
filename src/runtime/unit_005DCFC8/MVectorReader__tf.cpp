typedef unsigned int u32;

extern "C" void MReaderBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D5EA8;

extern int D_0088E350;

extern "C" void *MVectorReader__tf(void) {
    if (D_0088E350 == 0) {
        MReaderBase__tf();
        func_005BFB68(&D_0088E350, ((char *)"13MVectorReader"), &D_006D5EA8);
    }
    return &D_0088E350;
}
