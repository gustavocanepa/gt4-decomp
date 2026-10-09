typedef unsigned int u32;

extern "C" void HFrame__tf();
extern "C" void func_005C0E78(void *a0, void *a1, void *a2);

extern char D_0069E548[];
extern int D_006D5F40;

extern int D_0088ED60;

extern "C" void *func_005F0970(void) {
    if (D_0088ED60 == 0) {
        HFrame__tf();
        func_005C0E78(&D_0088ED60, D_0069E548, &D_006D5F40);
    }
    return &D_0088ED60;
}
