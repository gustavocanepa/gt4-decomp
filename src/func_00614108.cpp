typedef int s32;

extern "C" void func_00615148();
extern "C" void func_005BFB40(void *a0, void *a1, void *a2, s32 a3);

extern char D_006CF7D8[];
extern int D_006CF7E8;

static int D_008A1BA0;

extern "C" void *func_00614108(void) {
    if (D_008A1BA0 == 0) {
        func_00615148();
        func_005BFB40(&D_008A1BA0, D_006CF7D8, &D_006CF7E8, 1);
    }
    return &D_008A1BA0;
}
