typedef unsigned int u32;

extern "C" void func_00613918();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_0068BC18[];
extern int D_008A1BA0;

extern int D_0088D9A0;

extern "C" void *func_005C2050(void) {
    if (D_0088D9A0 == 0) {
        func_00613918();
        func_005BFB68(&D_0088D9A0, D_0068BC18, &D_008A1BA0);
    }
    return &D_0088D9A0;
}
