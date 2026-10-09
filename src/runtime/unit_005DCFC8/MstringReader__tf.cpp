typedef unsigned int u32;

extern "C" void MReaderBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_00699600[];
extern int D_006D5EA8;

extern int D_0088E320;

extern "C" void *MstringReader__tf(void) {
    if (D_0088E320 == 0) {
        MReaderBase__tf();
        func_005BFB68(&D_0088E320, D_00699600, &D_006D5EA8);
    }
    return &D_0088E320;
}
