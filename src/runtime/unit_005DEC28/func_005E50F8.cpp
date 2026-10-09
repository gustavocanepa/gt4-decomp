typedef unsigned int u32;

extern "C" void MReaderBase__tf();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern int D_006D5EA8;

extern int D_0088E570;

extern "C" void *func_005E50F8(void) {
    if (D_0088E570 == 0) {
        MReaderBase__tf();
        func_005BFB68(&D_0088E570, ((char *)"t12MArrayReader2Zt10std_vector2Z6MColorZt13std_allocator1Z6MColorZ12MColorReader"), &D_006D5EA8);
    }
    return &D_0088E570;
}
