typedef int s32;

extern "C" void func_00613DD8();
extern "C" void func_005BFB40(void *a0, void *a1, void *a2, s32 a3);

extern char D_006CC6E8[];
extern int D_006CC708;

extern int D_008A1BA0;

extern "C" void *func_00613918(void) {
    if (D_008A1BA0 == 0) {
        func_00613DD8();
        func_005BFB40(&D_008A1BA0, D_006CC6E8, &D_006CC708, 1);
    }
    return &D_008A1BA0;
}
