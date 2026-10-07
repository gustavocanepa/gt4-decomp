typedef unsigned int u32;

extern "C" void func_005FDDA8();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0069FD60[];
extern int D_0088F840;

extern int D_0088F1C0;

extern "C" void *func_005F64A0(void) {
    if (D_0088F1C0 == 0) {
        func_005FDDA8();
        func_005BFB68(&D_0088F1C0, D_0069FD60, &D_0088F840);
    }
    return &D_0088F1C0;
}
