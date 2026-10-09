typedef unsigned int u32;

extern "C" void func_00612828();
extern "C" void func_005BFB68(void *a0, void *a1, void *a2);

extern char D_006C8E28[];
extern int D_006D6280;

extern int D_008A1B10;

extern "C" void *func_00612868(void) {
    if (D_008A1B10 == 0) {
        func_00612828();
        func_005BFB68(&D_008A1B10, D_006C8E28, &D_006D6280);
    }
    return &D_008A1B10;
}
